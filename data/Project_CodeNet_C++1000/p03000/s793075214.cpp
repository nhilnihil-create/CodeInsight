#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int d = 0;
    int ans = 0;
    rep(i,n){
        d = d + l[i];
        if(d <= x) ans++;
    }
    cout << ans+1 << endl;
    return 0;
}