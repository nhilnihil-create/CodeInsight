#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{   
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    rep(i,n){
        cout << s[i] << t[i];
    }
    cout << endl;
    return 0;
}