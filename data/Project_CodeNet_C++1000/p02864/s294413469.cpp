#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e17;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1];
    }
    ll dp[310][310], ans = INF;
    fill(dp[0], dp[310], INF);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n + 1 - k; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            } else if (j == 1) {
                dp[i][j] = h[i];
            } else
                for (int l = 0; l < i; l++) {
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + max(0, h[i] - h[l]));
                }
        }
        ans = min(ans, dp[i][n + 1 - k]);
    }
    cout << ans << endl;
    return 0;
}