#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> dp(n,0);
    dp[0] = 1000;
    for(i = 1;i < n;++i){
        dp[i] = dp[i - 1];
        for(j = 0;j <= i-1;++j){
            ll v = dp[j]/a[j];
            ll w = dp[j] + (a[i] - a[j])*v;
            dp[i] = max(dp[i], w);
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}