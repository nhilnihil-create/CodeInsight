#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, T; cin >> N >> T;
    vector<int> A(N), B(N);
    REP(i, 0, N) cin >> A[i] >> B[i];

    vector<int> idx(N);
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](auto l, auto r) { return A[l] < A[r]; });

    vector<vector<int>> dp(N + 1, vector<int>(6001, 0));
    REP(i, 0, N) {
        REP(j, 0, 6000) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < T) dp[i + 1][j + A[idx[i]]] = max(dp[i + 1][j + A[idx[i]]], dp[i][j] + B[idx[i]]);
        }
    }

    int ans = 0;
    REP(i, 0, 6000) ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}