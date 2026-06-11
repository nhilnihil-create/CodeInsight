#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int i = 3; i <= n; ++i) {
        for (int j = 3; j <= i; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    cout << dp[n];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}