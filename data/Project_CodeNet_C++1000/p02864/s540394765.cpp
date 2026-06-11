#include<bits/stdc++.h>
using namespace std;

const int MAX = 301;
const long long INF = 1e18-1;
 
 
int main() {
    long long N, K; cin >> N >> K;
    long long H[MAX];
    for (int i = 0; i < N; i++) cin >> H[i];

    long long dp[MAX][MAX];

    for (int i = 0; i < MAX; i++) for (int j = 1; j < MAX; j++) dp[i][j] = INF;

    for (int i = 0; i < N; i++) dp[i][1] = H[i];

    for (int i = 1; i < N; i++) for (int k = 2; k < N - K + 1; k++) for (int l = 0; l < i; l++) {
        dp[i][k] = min(dp[i][k], dp[l][k-1]+max(0ll, H[i]-H[l]));
    }

    long long ans = INF;
    for (int i = 0; i < N; i++) ans = min(ans, dp[i][N - K]);

    cout << ans << endl;
    return 0;
}