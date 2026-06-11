#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, q;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& e: a) {
        std::cin >> e;
    }
    std::cin >> q;
    std::vector<int> b(q);
    int m = 0;
    for (auto& e: b) {
        std::cin >> e;
        m = std::max(m, e);
    }
    bool dp[21][2001];
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i]) {
                dp[i + 1][j] |= dp[i][j - a[i]];
            }
        }
    }
    for (auto&& e: b) {
        std::cout << (dp[n][e] ? "yes" : "no") << std::endl;
    }
}

