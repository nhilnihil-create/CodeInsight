#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    for (int i = 0; i < M; ++i)
        cin >> T[i];

    vector<vector<ll>> dp(N + 2, vector<ll>(M + 2));
    dp[0][0] = 1;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0 && S[i - 1] != T[j - 1])
                dp[i][j] -= dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
    }
    if (dp[N][M] < 0)
        dp[N][M] += MOD;
    cout << dp[N][M] << endl;

    return 0;
}
