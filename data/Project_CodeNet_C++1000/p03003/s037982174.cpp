#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

const int mod = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1));
    rep(i, N) rep(j, M) {
        dp[i + 1][j + 1] = ((dp[i][j + 1] + dp[i + 1][j] - dp[i][j]) % mod + mod) % mod;
        if (S[i] == T[j]) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
    }
    cout << dp[N][M] << "\n";
    return 0;
}
