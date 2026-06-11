#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int n = s.length() + 1;
    vector<int> a(n);
    rep(i,n-1){
        if(s[i] == '<'){
            a[i+1] = max(a[i+1], a[i]+1);
        }
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        if(s[i] == '>'){
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    ll ans = 0;
    rep(i,n){
        ans += a[i];
    }
    cout << ans << endl;
    
    return 0;
}