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
    int h, w, n; std::cin >> h >> w >> n;
    int x = std::max(h, w);
    std::cout << (n + x - 1) / x << std::endl;
    return 0;
}