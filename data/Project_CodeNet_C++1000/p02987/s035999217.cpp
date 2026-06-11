#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[0] == S[1]){
        if(S[2] == S[3] && S[0] != S[2]){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }else if(S[0] == S[2] && S[1] == S[3] || S[0] == S[3] && S[1] == S[2]){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
    }
    return 0;
}