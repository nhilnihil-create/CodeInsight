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
    int A, B, N; std::cin >> A >> B >> N;
    std::vector<int> a(A), b(B), x(N), y(N), c(N);
    for (int i = 0; i < A; i++) std::cin >> a[i];
    for (int i = 0; i < B; i++) std::cin >> b[i];
    for (int i = 0; i < N; i++) std::cin >> x[i] >> y[i] >> c[i];
    int ans = *std::min_element(a.begin(), a.end())
        + *std::min_element(b.begin(), b.end());
    for (int i = 0; i < N; i++) {
        ans = std::min(ans, a[x[i] - 1] + b[y[i] - 1] - c[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
