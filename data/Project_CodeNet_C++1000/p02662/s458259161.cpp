#include <bits/stdc++.h>
#define int long long
using namespace std;
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,sse4.2")

const int MOD = 998244353;

int calc(int k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return 2;
    } else if (k % 2 == 0) {
        int sq = calc(k / 2);
        return (sq * sq) % MOD;
    } else {
        return (2 * calc(k - 1)) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> kek(n);
    for (int i = 0; i < n; i++) {
        cin >> kek[i];
    }
    int dp[n][s + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j == 0) {
                dp[i][j] = calc(i + 1);
            } else if (i == 0) {
                if (kek[i] == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else {
                dp[i][j] += dp[i - 1][j] * 2;
                if (j >= kek[i]) dp[i][j] += dp[i - 1][j - kek[i]];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][s] << '\n';

    fflush(stdout);
    return 0;
}
