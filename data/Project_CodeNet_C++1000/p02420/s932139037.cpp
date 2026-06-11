#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string deck, buffer1, buffer2, result;
    int m, h, decklen;

    while(1){
        cin >> deck;
        if(deck == "-") break;
        decklen = deck.length();
        cin >> m;

        for(int i = 0; i < m; i++){
            scanf("%d", &h);
            buffer1 = deck.substr(0, h);
            buffer2 = deck.substr(h);
            deck = buffer2 + buffer1;
        }
        cout << deck << endl;
    }
    return 0;
}