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
    std::vector<std::string> s(n);
    std::vector<int> t(n);
    for (int i = 0; i < n; i++) std::cin >> s[i] >> t[i];
    int sum = std::accumulate(t.begin(), t.end(), 0);
    std::string x; std::cin >> x;
    for (int i = 0; i < n; i++) {
        sum -= t[i];
        if (s[i] == x) break;
    }
    std::cout << sum << std::endl;
    return 0;
}
