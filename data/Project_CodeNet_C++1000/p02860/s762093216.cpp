#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n%2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    int t = n/2;
    bool flag = true;
    rep(i,t){
        if(s[i] != s[i+t]) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}