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
    std::string s; std::cin >> s;
    int n = s.size();
    std::vector<int> dig(n);
    for (int i = 0; i < n; i++) dig[i] = s[i] - '0';
    auto chmin = [](int &a, int b) { return a = std::min(a, b); };
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(3, -1));
    auto func = [&](const auto &self, int t, int state) -> int {
        if (t >= n) return ~state&1 ? 0 : 1e9;
        if (dp[t][state] != -1) return dp[t][state];
        int ret = 1e9;
        if (state == 0) {
            chmin(ret, self(self, t + 1, 0) + dig[t]);
            chmin(ret, self(self, t + 1, 1) + dig[t] + 1);
        }
        if (state == 1) {
            chmin(ret, self(self, t + 1, 0) + 10 - dig[t]);
            chmin(ret, self(self, t + 1, 1) + 9 - dig[t]);
        }
        if (state == 2) {
            chmin(ret, self(self, t + 1, 2) + dig[t]);
            chmin(ret, self(self, t + 1, 1) + dig[t] + 1);
        }
        return dp[t][state] = ret;
    };
    std::cout << std::min(func(func, 0, 2), 1 + func(func, 0, 1)) << std::endl;
    return 0;
}
