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
    int p, q, r; std::cin >> p >> q >> r;
    std::cout << std::min({ p + q, q + r,r + p }) << std::endl;
    return 0;
}
