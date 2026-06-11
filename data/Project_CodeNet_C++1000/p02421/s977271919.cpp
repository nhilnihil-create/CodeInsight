#include <bits/stdc++.h>
using namespace std;

string taro,hana,card[2];
int N,Tp,Hp;

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> taro >> hana;
        if(taro == hana){
            Tp++; Hp++;
            continue;
        }
        card[0] = taro; card[1] = hana;
        sort(card, card +2);
        if(card[1] == taro) Tp+=3;
        else Hp+=3;
    }

    cout << Tp << " " << Hp << endl;
    return 0;
}