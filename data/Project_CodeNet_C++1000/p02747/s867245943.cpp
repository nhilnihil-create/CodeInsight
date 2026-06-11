#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    cin >> S;
    if(S.size()%2 == 1){
        cout << "No" << endl;
    }
    else{
        for(int i = 0; i < S.size(); i+=2){
            if(S[i] != 'h' || S[i+1] != 'i'){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
}