#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[2005][2005];

int main() {
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater<pair<ll, ll>>());
    ll ans = 0;
    for (ll l = 0; l < n; l++) {
        for (ll r = 0; r < n; r++) {
            if (l + r == n) {
                ans = max(ans, dp[l][r]);
                break;
            }
            dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + a[l + r].first * abs(a[l + r].second - l));
            dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + a[l + r].first * abs(a[l + r].second - (n - 1 - r)));
        }
    }
    cout << ans << endl;
}