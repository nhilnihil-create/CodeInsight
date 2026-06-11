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
#include <cassert>
#include <random>


int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    std::multiset<int> s;
    s.insert(-1); s.insert(-1);
    s.insert(n); s.insert(n);
    long long ans = 0;
    for (int i : id) {
        auto itr = s.lower_bound(i);
        long long r0 = *itr;
        itr++;
        long long r1 = *itr;
        itr--;
        itr--;
        long long l0 = *itr;
        itr--;
        long long l1 = *itr;
        ans += a[i]*(r1 - r0)*(i - l0);
        ans += a[i] * (l0 - l1)*(r0 - i);
        s.insert(i);
    }
    std::cout << ans << std::endl;
    return 0;
}
