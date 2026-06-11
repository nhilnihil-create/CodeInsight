#include <bits/stdc++.h>
using namespace std;

int main(){

    int K;
    string S;
    cin >> K >> S;

    string res = S;
    if(S.length() > K){
        res = S.substr(0,K) + "...";
    }

    cout << res;
    return 0;
}