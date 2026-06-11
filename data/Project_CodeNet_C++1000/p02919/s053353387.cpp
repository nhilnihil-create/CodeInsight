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
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) std::cin >> p[i];
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return p[i] > p[j];
    });
    std::multiset<int> s;
    s.insert(-1); s.insert(-1);
    s.insert(n); s.insert(n);
    long long ans = 0;
    for (int i : id) {
        auto iter = s.lower_bound(i);
        int r1 = *iter;
        int r2 = *++iter;
        --iter;
        int l1 = *--iter;
        int l2 = *--iter;
        ans += (long long)(r2 - r1)*(i - l1)*p[i];
        ans += (long long)(l1 - l2)*(r1 - i)*p[i];
        s.insert(i);
    }
    std::cout << ans << std::endl;
    return 0;
}