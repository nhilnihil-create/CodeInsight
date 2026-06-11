#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int card_num;
    int shuffle_num;
    int p, c;
    while(1){
        cin >> card_num;
        cin >> shuffle_num;
        if(card_num * shuffle_num == 0){
            break;
        }
        int card[card_num];
        for(int i = 0; i < card_num; i++){
            card[i] = card_num - i;
        }
        for(int i = 0; i < shuffle_num; i++){
            cin >> p;
            cin >> c;
            rotate(card, card + p - 1, card + c + p - 1);
        }
        cout << card[0] << endl;
    }
    return 0;
}