#include <iostream>
#include <algorithm>
using namespace std;

#define INF int(1e9)

int n, m, ans;
int c[21], dp[50001];
/*
int c[21], memo[50001];
int solve(int v) {
    if (v < 0) return INF;
    if (v == 0) return 0;
    if (memo[v] != INF) return memo[v];

    int ret = INF;

    for (int i = 0; i < m; ++i) {
        ret = min(ret, solve(v - c[i]) + 1);
    }

    return memo[v] = ret;
}
*/

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> c[i];

    //ans = solve(n);

    fill(dp, dp + 50001, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    //cout << ans << endl;
    cout << dp[n] << endl;

    return 0;
}