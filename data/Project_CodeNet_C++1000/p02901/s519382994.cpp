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

int main() {
    const int INF = 1000000000;
    
    int N, M;
    cin >> N >> M;
    vector<int> a(M, 0), c(M, 0);
    rep(i, M) {
        int b;
        cin >> a[i] >> b;
        rep(j, b) {
            int x;
            cin >> x;
            --x;
            c[i] += (1 << x);
        }
    }
    vector<vector<int>> dp(M + 1, vector<int>(1 << N, INF));
    dp[0][0] = 0;
    rep(i, M) rep(j, 1 << N) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j | c[i]] = min(dp[i + 1][j | c[i]], dp[i][j] + a[i]);
    }
    if (dp[M][(1 << N) - 1] == INF) cout << -1 << "\n";
    else cout << dp[M][(1 << N) - 1] << "\n";
    return 0;
}
