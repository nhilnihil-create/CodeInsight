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
    std::vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++) std::cin >> a[i];
    std::sort(a.rbegin(), a.rend());
    std::multiset<int, std::greater<int>> par, res, buf;
    par.insert(a[0]);
    for (int i = 1; i < (1 << n); i++) res.insert(a[i]);
    for (int i = 0; i < n; i++) {
        for (auto p : par) {
            auto iter = res.upper_bound(p);
            if (iter == res.end()) {
                std::cout << "No" << std::endl;
                return 0;
            }
            buf.insert(*iter);
            res.erase(iter);
        }
        for (auto p : buf) {
            par.insert(p);
        }
        buf.clear();
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
