#include <bits/stdc++.h>
using namespace std;
long long const MOD = 1000000007;
long long dp[2010][2010] = {};

int main() {
    int N, M; cin >> N >> M;
    vector<int> S(N), T(M);
    for(int i=0; i<N; ++i) cin >> S[i];
    for(int j=0; j<M; ++j) cin >> T[j];

    for(int j=0; j<=M; ++j) dp[0][j] = 1;
    for(int i=0; i<=N; ++i) dp[i][0] = 1;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            if(S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + 1] %= MOD;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + MOD) % MOD;
        }
    }
    cout << dp[N][M] << endl;
}