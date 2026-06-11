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

    vector<vector<int>> dp1(N + 1, vector<int>(T, 0));
    vector<vector<int>> dp2(N + 1, vector<int>(T, 0));
    REP(i, 0, N) {
        REP(j, 0, T) {
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
            if (j + A[i] < T) dp1[i + 1][j + A[i]] = max(dp1[i + 1][j + A[i]], dp1[i][j] + B[i]);
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        REP(j, 0, T) {
            dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
            if (j + A[i] < T) dp2[i][j + A[i]] = max(dp2[i][j + A[i]], dp2[i + 1][j] + B[i]);
        }
    }

    int ans = 0;
    REP(i, 0, N) {
        REP(j, 0, T) {
            // cout << "# j : " << j << ", T - j - 1 : " << T - j - 1 << endl;
            // cout << "--> " << dp1[i][j] << " " << dp2[i + 1][T - j - 1] << endl;
            ans = max(ans, dp1[i][j] + dp2[i + 1][T - j - 1] + B[i]);
        }
    }
    cout << ans << endl;

    return 0;
}