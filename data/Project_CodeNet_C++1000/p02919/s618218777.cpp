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
    std::vector<std::pair<long long, int>> p(n);
    for (int i = 0; i < n; i++) std::cin >> p[i].first, p[i].second = i;
    std::sort(p.rbegin(), p.rend());
    std::multiset<int> s;
    s.insert(-1); s.insert(-1);
    s.insert(n); s.insert(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto iter = s.lower_bound(p[i].second);
        long long r1 = *iter;
        long long r2 = *(++iter);
        long long l1 = *(--(--iter));
        long long l2 = *(--iter);
        ans += p[i].first*(r2 - r1)*(p[i].second - l1);
        ans += p[i].first*(r1 - p[i].second)*(l1 - l2);
        s.insert(p[i].second);
    }
    std::cout << ans << std::endl;
    return 0;
}
