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
    int x; std::cin >> x;
    for (int i = 1; i <= 1000; i++) {
        if (i * 100 <= x && x <= i * 100 + i * 5) {
            std::cout << 1 << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}
