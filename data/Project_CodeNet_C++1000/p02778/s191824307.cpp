#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    string s;
    cin >> s;
    rep(i,s.size()){
        s[i] = 'x';
    }
    cout << s << endl;
}