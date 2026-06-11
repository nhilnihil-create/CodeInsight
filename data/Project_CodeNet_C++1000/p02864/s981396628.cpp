#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
using i64 = int64_t;
i64 n, k, dp[302][302];
vector<i64> h;
int main() {
    cin >> n >> k;
    h.resize(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 1e18;
        }
    }
    for (i64 i = 1; i <= n + 1; ++i) {
        for (i64 j = 0; j <= k && i - j - 1 >= 0; ++j) {
            for (i64 l = 0; j + l <= k; ++l) {
                dp[i][j + l] = min(
                    dp[i][j + l],
                    dp[i - j - 1][l] + max(i64(0), h[i] - h[i - j - 1])
                );
            }
        }
    }
    i64 ans = 1e18;
    for (i64 j = 0; j <= k; ++j) ans = min(ans, dp[n + 1][j]);
    cout << ans << endl;
    return 0;
}