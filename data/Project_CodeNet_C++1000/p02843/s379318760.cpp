#include<bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;

    bool flg = false;

    int num = X / 100;
    for(int i=1; i<= num; ++i){
        if(X >= 100*i && X <= 105*i){
            flg = true;
            break;
        }
    }
    if(flg) cout << 1 << endl;
    else cout << 0 << endl;
}