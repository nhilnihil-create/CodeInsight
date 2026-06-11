#include<iostream>
#include<string>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool ans = true;
    if (S[2] != S[3]) ans = false;
    if (S[5] != S[4]) ans = false;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}