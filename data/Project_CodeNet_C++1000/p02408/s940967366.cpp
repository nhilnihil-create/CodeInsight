#include<iostream>
using namespace std;
#include<string>
// ???????????£???????????????????????????????????????

int main()
{
    int n, i;
    string suit;
    int num;
    int cards[52];

    for(i = 0; i < 52; i++) cards[i] = 0;

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> suit >> num;
        if(suit == "S") cards[num - 1] = 1;
        if(suit == "H") cards[num + 12] = 1;
        if(suit == "C") cards[num + 25] = 1;
        if(suit == "D") cards[num + 38] = 1;
    }
    for(i = 0; i < 52; i++){
        if(cards[i] == 1) continue;
        if(i < 13){
            cout << "S " << i + 1;
        }else if(i < 26){
            cout << "H " << i - 12;
        }else if(i < 39){
            cout << "C " << i - 25;
        }else{
            cout << "D " <<  i - 38;
        }
        cout << endl;
    }

    return 0;
}