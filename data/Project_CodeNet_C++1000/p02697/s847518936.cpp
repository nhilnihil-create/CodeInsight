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
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> ans;
    if (n & 1) {
        for (int i = 0; i < m; i++)
            ans.emplace_back(i + 1, n - i);
    }
    else {
        for (int i = 0; i < m; i++) {
            if (i & 1) ans.emplace_back(
                n / 2 + 1 + i / 2, n - 1 - i / 2);
            else ans.emplace_back(
                1 + i / 2, n / 2 - i / 2);
        }
    }
    for (auto &p : ans)
        std::cout << p.first << " " << p.second << std::endl;
    return 0;
}
