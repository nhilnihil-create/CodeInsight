#include <bits/stdc++.h>
using i64 = long long;

int main() {
    constexpr i64 inf = std::numeric_limits<i64>::max() / 2;
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> h(n + 2);
    for (int i = 1; i <= n; i++) std::cin >> h[i];

    std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n + 1; i++) for (int j = 0; j < i; j++) {
        int c = i - j - 1;
        i64 d = std::max(h[i] - h[j], 0ll);
        for (int l = 0; l + c <= k; l++) {
            dp[i][l + c] = std::min(dp[i][l + c], dp[j][l] + d);
        }
    }

    std::cout << *std::min_element(dp.back().begin(), dp.back().end()) << std::endl;

    return 0;
}
