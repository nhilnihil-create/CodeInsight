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
    constexpr ll mod = 1000000007LL;
    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<ll>> sum(n, vector<ll>(m));
    dp[0][0] = sum[0][0] = s.front() == t.front();
    for (int i = 1; i < n; ++i) {
        dp[i][0] = s[i] == t.front();
        sum[i][0] = dp[i][0] + sum[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
        dp[0][i] = s.front() == t[i];
        sum[0][i] = dp[0][i] + sum[0][i - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (s[i] == t[j])
                dp[i][j] = sum[i - 1][j - 1] + 1;
            sum[i][j] = ((sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]) % mod + mod) % mod;
            sum[i][j] += dp[i][j];
            sum[i][j] %= mod;
        }
    }
    cout << (sum.back().back() + 1) % mod << endl;
    return 0;
}