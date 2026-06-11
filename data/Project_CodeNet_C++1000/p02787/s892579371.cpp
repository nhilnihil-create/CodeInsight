#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL<<60; // 無限大を表す値

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    vector<vector<long long>> dp(N+1, vector<long long>(H+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= H; ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j] = min(dp[i+1][j], dp[i+1][max(j-A[i], 0)] + B[i]);
        }
    }
    cout << dp[N][H] << endl;
}