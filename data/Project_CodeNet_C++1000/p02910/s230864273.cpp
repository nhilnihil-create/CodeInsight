#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    rep(i,len){
        if(s[i] == 'U' || s[i] == 'D') continue;
        if(i%2 == 0 && s[i] == 'L'){
            cout << "No" << endl;
            return 0;
        }
        if(i%2 == 1 && s[i] == 'R'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}