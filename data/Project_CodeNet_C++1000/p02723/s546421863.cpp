#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    for (int i=0;i<6;i++){
        cin >> S[i];
    }
    for (int i=0;i<6;i++){
        if(S[2]==S[3] && S[4] == S[5]){
            cout <<"Yes" << endl;
            break;
        }
        else {
            cout << "No" << endl;
            break;
        }
    }
}