#include <iostream>
#include <vector>
#include <numeric>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;

    const int x = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<>());
    for (const int e : a) {
        std::cout << (x ^ e) << ' ';
    }
    std::cout << std::endl;

    return 0;
}
