#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, 0, M) {
        int b; cin >> A[i] >> b;
        REP(j, 0, b) {
            int c; cin >> c; B[i] |= (1 << (c - 1));
        }
    }

    // REP(i, 0, M) {
    //     cout << A[i] << " " << bitset<3>(B[i]) << endl;
    // }

    vector<vector<int>> dp(M + 1, vector<int>(1 << N, 1 << 30));
    dp[0][0] = 0;
    REP(i, 0, M) {
        REP(j, 0, 1 << N) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j | B[i]] = min(dp[i + 1][j | B[i]], dp[i][j] + A[i]);
        }
    }

    // REP(i, 0, M + 1) {
    //     REP(j, 0, 1 << N) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // } 

    if (dp[M][(1 << N) - 1] < (1 << 30)) cout << dp[M][(1 << N) - 1] << endl;
    else cout << -1 << endl;
    return 0;
}