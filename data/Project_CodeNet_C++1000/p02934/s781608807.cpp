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
    double s = 0;
    for (int i = 0; i < n; i++) {
        double a; std::cin >> a;
        s += 1. / a;
    }
    printf("%.12f\n", 1. / s);
    return 0;
}