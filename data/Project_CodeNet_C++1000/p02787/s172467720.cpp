#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
int main() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<vector<int>> dp(1100, vector<int>(11000, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][min(h, j+a[i])]
                = min(dp[i+1][min(h, j+a[i])], dp[i+1][j] + b[i]);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}