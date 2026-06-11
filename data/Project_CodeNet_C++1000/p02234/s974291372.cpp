#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>

#define DEBUG

#ifdef DEBUG

#define printd printf

#else

#define printd(...)

#endif

int main() {
    int n;
    int shapes[100][2];

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> shapes[i][0] >> shapes[i][1];
    }

    constexpr uint64_t INF = UINT64_MAX;
    uint64_t dp[100][100];
    for (int i = 0; i < 100; i++) {
        dp[i][i] = 0;
    }
    for (int width = 2; width <= n; width++) {
        for (int l = 0; l <= n - width; l++) {
            auto min = INF;
            for (int split = l + 1; split < l + width; split++) {
                auto times = dp[l][split - 1] + dp[split][l + width - 1] + shapes[l][0] * shapes[split][0] * shapes[l + width - 1][1];
                if (times < min) {
                    min = times;
                }
            }
            dp[l][l + width - 1] = min;
        }
    }
    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}

