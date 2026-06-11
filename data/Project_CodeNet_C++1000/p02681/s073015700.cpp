#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{   
    string s, t;
    cin >> s  >> t;
    int n = s.length();
    rep(i,n){
        if(s[i] != t[i]){
            cout << "No" <<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}