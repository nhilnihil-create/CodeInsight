#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.length();
    bool flg = true;
    for(int i=0; i<N/2; i++){
        if(S.at(i) != S.at(N-i-1)) flg = false;
    }
    for(int i=0; i<N/4; i++){
        if(S.at(i) != S.at(N/2-i-1)) flg = false;
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}