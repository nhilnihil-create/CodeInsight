#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    string s;
    cin >> s;
    if(s[0] == s[1]){
        cout << "Bad" << endl;
    }else if(s[1] == s[2]){
        cout << "Bad" << endl;
    }else if(s[2] == s[3]){
        cout << "Bad" << endl;
    }else{
        cout << "Good" << endl;
    }
}