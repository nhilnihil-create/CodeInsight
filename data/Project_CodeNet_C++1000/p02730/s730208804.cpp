#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    string X = S.substr(0,S.size()/2);
    string Y = S.substr(S.size()/2+1);
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != S[S.size()-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0; i < S.size()/2; i++) {
        if(X[i] != X[S.size()/2-1-i]) {
            cout << "No" << endl;
            return 0;
        }
        else if(Y[i] != Y[S.size()/2-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
