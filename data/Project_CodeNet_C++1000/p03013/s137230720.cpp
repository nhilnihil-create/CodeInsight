#include <iostream>
#include <vector>

int main() {
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<int> dp(n + 1);
    for (int i = 0; i < m; i++) {
        int a{};
        std::cin >> a;
        dp[a] = -1;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue;
        for (int j = 1; j <=2; j++) {
            if (i + j > n) break;
            if (dp[i + j] == -1) continue;
            dp[i + j] += dp[i];
            if (dp[i + j] > 1000000007) dp[i + j] -= 1000000007;
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}