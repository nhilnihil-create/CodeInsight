#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Spell {
    int64_t damage{};
    int64_t cost{};
};

int main() {
    int64_t h{}, n{};
    std::cin >> h >> n;
    std::vector<Spell> spells(n);
    for (int64_t i = 0; i < n; i++) {
        std::cin >> spells[i].damage >> spells[i].cost;
    }

    std::vector<int64_t> dp(h + 1, std::numeric_limits<int64_t>::max());
    dp[0] = 0;
    for (int64_t i = 0; i < h; i++) {
        if (dp[i] == std::numeric_limits<int64_t>::max()) continue;
        for (int64_t j = 0; j < n; j++) {
            const auto total = std::min(h, i + spells[j].damage);
            dp[total] = std::min(dp[total], dp[i] + spells[j].cost);
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}