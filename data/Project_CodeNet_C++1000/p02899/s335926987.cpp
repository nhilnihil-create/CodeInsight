#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;
    vector<int> ans(n);
    rep(i,n) ans[a[i]] += i+1;
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}