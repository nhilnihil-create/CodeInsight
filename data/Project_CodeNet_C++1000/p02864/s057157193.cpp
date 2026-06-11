#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,K;
ll H[310];
ll dp[310][310][310];
ll inf = 1e18;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> H[i+1];
    for (int i = 0; i < 310; i++)
        for (int j = 0; j < 310; j++)
            for (int k = 0; k < 310; k++)
                dp[i][j][k] = inf;

    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= K; k++) {
                //not delete
                if (i - k >= 0 && j - k >= 0)
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i - k][j - k][0] + max(0LL, H[i + 1] - H[i - k]));
                //delete
                if (j + 1 <= K)
                    dp[i+1][j+1][k+1] = min(dp[i+1][j+1][k+1], dp[i][j][k]);
            }
        }
    }

    ll ans = inf;
    for (int j = 0; j <= K; j++) 
        for (int k = 0; k <= K; k++) 
            ans = min(ans, dp[N][j][k]);
    cout << ans << endl;
    return 0;
}
