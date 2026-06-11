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
    int n; std::cin >> n;
    std::vector<std::vector<int>> ans(n, std::vector<int>(n));
    auto func = [&](auto &self, int left = 0, int right = -1, int c = 1) -> void {
        if (right == -1) right = n;
        int m = (left + right) / 2;
        for (int i = left; i < m; i++) {
            for (int j = m; j < right; j++) {
                ans[i][j] = c;
            }
        }
        if (right - left <= 2) return;
        self(self, left, m, c + 1);
        self(self, m, right, c + 1);
    };
    func(func);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            std::cout << ans[i][j] << " \n"[j == n - 1];
    return 0;
}
