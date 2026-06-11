#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
ll dp[100007][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string l;
    cin >> l;
    int n = l.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1][1] += 3 * dp[i][1];
        if (l[i] == '1') {
            dp[i + 1][0] += dp[i][0] * 2;
            dp[i + 1][1] += dp[i][0];
        } else {
            dp[i + 1][0] += dp[i][0];
        }
        dp[i + 1][0] %= mod;
        dp[i + 1][1] %= mod;
    }

    ll ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << '\n';
    return 0;
}

