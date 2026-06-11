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
    rep(i, m + 1) { dp[0][i] = 1; }

    repd(i, 1, n + 1) {
        repd(j, 1, m + 1) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            } else {
                dp[i][j] =
                    (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mod) %
                    mod;
            }
        }
    }
    cout << dp[n][m] << endl;
}
