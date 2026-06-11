#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)

int main() {
    int n, m;
    cin >> n >> m;
    ll s[n], t[m];

    rep(i, n) { cin >> s[i]; }
    rep(j, m) { cin >> t[j]; }

    ll dp[n + 1][m + 1];

    rep(i, n + 1) { dp[i][0] = 1; }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
            } else {
                dp[i + 1][j + 1] =
                    (dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + mod) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
}
