#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
ll dp[2005][2005];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> S(n);
    vector<int> T(m);
    rep(i, n) cin >> S[i];
    rep(i, m) cin >> T[i];
    rep(i, n+1) dp[i][0] = 1;
    rep(i, m+1) dp[0][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if (S[i-1] != T[j-1]) dp[i][j] -= dp[i-1][j-1];
            dp[i][j] += MOD;
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}