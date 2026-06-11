#include <iostream>
#include <vector>
#include <string>
using namespace std;

static const int all = 52;

int main(void) {
    bool cards[all];
    char inputSute;
    int N, inputCard;
    cin >> N;

    for(int i=0; i<all; i++) {
        cards[i] = true;
    }

    while(N-- > 0) {
        cin >> inputSute >> inputCard;
        switch(inputSute) {
            case 'S': inputCard += 0; break;
            case 'H': inputCard += 13; break;
            case 'C': inputCard += 26; break;
            case 'D': inputCard += 39; break;
        }
        cards[inputCard-1] = false;
    }

    for(int i=0; i < all; i++) {
        if(cards[i]) {
            switch(i / 13) {
                case 0: cout << "S "; break;
                case 1: cout << "H "; break;
                case 2: cout << "C "; break;
                case 3: cout << "D "; break;
            }
            cout << (i % 13) + 1 << endl;
        }
    }

    return 0;
}