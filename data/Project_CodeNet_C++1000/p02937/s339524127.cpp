#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    std::string s, t; std::cin >> s >> t;
    int n = s.size();
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(26, -1e18));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 'z' - 'a'; j++) {
            dp[i][j] = dp[i + 1][j] + 1;
            if (s[(i + 1)%n] == 'a' + j) dp[i][j] = 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 'z' - 'a'; j++) {
            if (dp[i][j] <= 0) {
                dp[i][j] = dp[(i + 1) % n][j] + 1;
            }
        }
    }

    long long pos = 0;
    int m = t.size();
    for (int i = 0; i < m; i++) {
        if (i == 0 && s[0] == t[0]) continue;
        if (dp[pos % n][t[i] - 'a'] <= 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        pos += dp[pos % n][t[i] - 'a'];
    }
    std::cout << pos + 1 << std::endl;
    return 0;
}
