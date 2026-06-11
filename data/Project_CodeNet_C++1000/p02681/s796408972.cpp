#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, T, Ts, Ss;
    cin >> S >> T;
    Ts = T.at(T.size()-1);
    Ss = S + Ts;

    if(Ss == T){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}