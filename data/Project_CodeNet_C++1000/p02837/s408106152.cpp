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

int N;
std::vector < std::vector < std::pair<int, int>>> v;

bool check(int& bit) {
    for (int i = 0; i < N; ++i) {
        if (!(bit & (1 << i)))
            continue;
        for (auto& r : v[i]) {
            if ((r.second == 1 && !(bit & (1 << r.first)))
                || (r.second == 0 && (bit & (1 << r.first)))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        int a; std::cin >> a;
        v[i].resize(a);
        for (int j = 0; j < a; ++j) {
            std::cin >> v[i][j].first >> v[i][j].second;
            --v[i][j].first;
        }
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        if (check(bit)) {
            int count = 0;
            for (int i = 0; i < N; ++i) {
                if (bit & (1 << i))
                    ++count;
            }
            ans = std::max(ans, count);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}