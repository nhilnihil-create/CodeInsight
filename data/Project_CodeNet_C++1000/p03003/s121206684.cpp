#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    // n == 1 || m == 1
    // otherwise
    constexpr ll mod = 1000000007LL;
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(4)));
    dp[0][0][0] = 1;
    dp[0][0][3] = s.front() == t.front();

    for (int i = 1; i < n; ++i) {
        dp[i][0][0] = 1;
        dp[i][0][2] = dp[i - 1][0][2] + dp[i - 1][0][3];
        dp[i][0][3] = s[i] == t.front();
    }

    for (int i = 1; i < m; ++i) {
        dp[0][i][0] = 1;
        dp[0][i][1] = dp[0][i - 1][1] + dp[0][i - 1][3];
        dp[0][i][3] = s.front() == t[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                dp[i][j][0] += dp[i - 1][j - 1][k];
                dp[i][j][0] %= mod;
            }

            dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][3];
            dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][3];

            if (s[i] == t[j])
                dp[i][j][3] = dp[i][j][0];

            dp[i][j][1] %= mod;
            dp[i][j][2] %= mod;
            dp[i][j][3] %= mod;
        }
    }

    ll ans = 0;
    for (int k = 0; k < 4; ++k) {
        ans += dp.back().back()[k];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}