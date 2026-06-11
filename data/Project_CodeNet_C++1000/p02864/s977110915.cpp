#include <bits/stdc++.h>
using namespace std;

long long dp[310][610];

int main() {
    int n, k; cin >> n >> k;
    vector<long long> h(n+1, 0);
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= 2*n; j++) dp[i][j] = 1e16;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) cin >> h[i+1];
    for (int i = 0; i <= n; i++) {
        for (int z = 0; z <= n; z++) {
            for (int j = i+1; j <= n; j++) {
                dp[j][z+1] = min(dp[j][z+1], dp[i][z] + max(0LL, h[j]-h[i]));
            }
            dp[n+1][z] = min(dp[n+1][z], dp[i][z]);
        }
    }
    long long ans = 1e18;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n+1][n-i]);
    cout << ans << endl;
    return 0;
}