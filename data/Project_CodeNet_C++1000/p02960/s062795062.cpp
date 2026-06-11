#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    int N = s.size();
    ll MOD = 1000000007;

    vector<vector<ll>> dp(N + 10, vector<ll>(13, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        rep(j, 13) {
            if (s[i] == '?') {
                rep(k, 10) {
                    dp[i + 1][(j * 10 + k) % 13] += dp[i][j];
                    dp[i + 1][(j * 10 + k) % 13] %= MOD;
                }
            } else {
                ll num = (s[i] - '0');
                dp[i + 1][(j * 10 + num) % 13] += dp[i][j];
                dp[i + 1][(j * 10 + num) % 13] %= MOD;
            }
        }
    }

    cout << dp[N][5] << endl;
}