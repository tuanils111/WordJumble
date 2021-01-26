//The classic word jumble game where the player can ask for hint
#include<bits/stdc++.h>
using namespace std;
int main(){
    int score=0;
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS]={
        {"wall", "Buc tuong"},
        {"glasses","Cai guong"},
        {"labored", "Cong viec"},
        {"persitent","Ben bi"},
        {"jumble","Lon xon"},
        {"chilvary","Hiep si"},
        {"league","lien doan"},
        {"stranger","nguoi la"},
        {"programmer","lap trinh vien"},
        {"president","tong thong"}
    };

    srand((time(0)));

    int choice = (rand()%NUM_WORDS);
    string theWord = WORDS[choice][WORD];//word to guess
    string theHint = WORDS[choice][HINT];//hint

    //to jumble the word

    string jumble = theWord; //jumble version of the word
    int length = jumble.size();
    for(int i = 0; i < length; i++){
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        swap(jumble[index1],jumble[index2]);
        score=length; //score based on the length of the word
    }

    cout <<"\t\tWelcome the Word Jumble Game!\n\n";
    cout <<"Unscramble the letters to make the a word.\n";
    cout <<"Enter 'hint' for a hint.\n";
    cout <<"Enter 'quit' to quit the game.\n\n";
    cout <<"You have "<<score<<" scores is the length of the word. \n";
    cout <<"The word jumble is: " << jumble<<" ";

    string guess;
    cout <<"\n\nYour guess:";
    cin >> guess;

    //game loop
    //subtracts points for hint or if you guess wrong
    while((guess != theWord) && (guess != "quit")){
        if(guess == "hint"){
            score --;
            cout << theHint;
            cout<<"\nYour score is "<<score;

        }
        else{
            score--;
            cout << "Sorry, that is not it. Your score is "<<score;
        }
        if(score==0){
            cout<<"\n\nYour score is 0 \nGame over! You lose!\n";
            return 0;
        }
        cout <<"\n\nYour guess:";
        cin >> guess;
    }
    if(guess == theWord){
        cout <<"\nThat it!, You guessed it!\n";
        cout<<"You won! You have a score of "<<score<<endl;
        cout <<"\nThank for playing!\n";
        return 0;
    }
    system("pause");
    return 0;
}
