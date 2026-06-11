#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<long long> H(N + 1, 0);
    for(int i=1; i<=N; ++i) cin >> H[i];

    if(K == 0) {
        long long res = H[1];
        for(int i=2; i<=N; ++i) res += max(H[i] - H[i - 1], 0LL);
        cout << res << endl;
    } else {
        const long long INF = 1001001001001001001;
        vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, INF));
        for(int i=0; i<=N; ++i) {
            dp[i][0] = 0;
            dp[i][1] = H[i];
        }

        for(int i=2; i<=N; ++i) {
            for(int j=2; j<=N; ++j) {
                for(int k=1; k<i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0LL, H[i] - H[k]));   
                }
            }
        }

        long long res = 1001001001001001001;
        for(int i=1; i<=N; ++i) res = min(res, dp[i][N - K]);
        cout << res << endl;
    }
}