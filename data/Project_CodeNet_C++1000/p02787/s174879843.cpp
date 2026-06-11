#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL<<60; // 無限大を表す値

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    int maxA = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        maxA = max(maxA, A[i]);
    }
    int W = H + maxA;

    vector<vector<long long>> dp(N+1, vector<long long>(W+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if (j-A[i] >= 0) {
                dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-A[i]] + B[i]);
            }
        }
    }

    long long result = INF;
    for (int j = H; j <= W; ++j) result = min(result, dp[N][j]);
    cout << result << endl;
}