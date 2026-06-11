#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long
#define PI 3.14159265358979323846

using namespace std;
int main() {
    intt N; std::cin >> N;
    std::vector<intt> L(N);
    for (auto& r : L)
        std::cin >> r;
    std::sort(L.begin(), L.end());
    int ans = 0;
    for (intt i = 0; i < N - 1; ++i) {
        for (intt j = i + 1; j < N; ++j) {
            intt k = std::lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
            ans += std::max((int)(k - (j + 1)), 0);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}