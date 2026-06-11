#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    rep(i, 0, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<ll,ll>>());
    vector<vector<ll>> dp(n+10, vector<ll>(n+10, 0));
    rep(i, 0, n) {
        rep(l, 0, i+1) {
            ll r = i - l;
            dp[l+1][r] = max(dp[l+1][r], dp[l][r] + a[i].first * (a[i].second - l));
            dp[l][r+1] = max(dp[l][r+1], dp[l][r] + a[i].first * ((n-1 - r) - a[i].second));
        }
    }
    ll ans = 0;
    rep(i, 0, n+1) ans = max(ans, dp[i][n-i]);
    cout << ans << endl;
    return 0;
}