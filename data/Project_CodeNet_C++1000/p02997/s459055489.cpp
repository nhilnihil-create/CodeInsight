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


int n, k;
std::vector<int> buf = { 1 };

void separate(int cursum=1, int comb=0) {
    comb += (cursum - buf.back())*buf.back();
    if (comb == k) {
        throw 1;
    }
    for (int i = buf.back(); i + cursum <= n - 1; i++) {
        buf.push_back(i);
        separate(cursum + i, comb);
        buf.pop_back();
    }
}


int main() {
    std::cin >> n >> k;
    if (k > (n - 1)*(n - 2) / 2) {
        std::cout << -1 << std::endl;
        return 0;
    }
    bool found = false;
    try {
        separate();
    } catch(int) {
        found = true;
    }
    if (!found) {
        std::cout << -1 << std::endl;
        return 0;
    }
    int sum = std::accumulate(buf.begin(), buf.end(), 0);
    std::vector<std::pair<int, int>> ans;
    int pos = 0;
    for (int t : buf) {
        for (int i = pos; i < pos + t; i++) {
            for (int j = i + 1; j < pos + t; j++) {
                ans.emplace_back(i + 1, j + 1);
            }
            for (int j = sum; j < n; j++) {
                ans.emplace_back(i + 1, j + 1);
            }
        }
        pos += t;
    }
    for (int i = sum; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans.emplace_back(i + 1, j + 1);
        }
    }
    std::cout << ans.size() << std::endl;
    for (const auto &e : ans) {
        std::cout << e.first << " " << e.second << std::endl;
    }
    return 0;
}
