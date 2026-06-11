#include <iostream>
#include <vector>

int main() {
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> count(N + 1, 0);
    for (int64_t i = 1; i < N + 1; ++i) {
        for (int64_t j = i; j < N + 1; j += i) {
            count[j] += 1;
        }
    }

    int64_t ans = 0;
    for (int64_t i = 1; i < N + 1; ++i) {
        ans += i * count[i];
    }
    std::cout << ans << std::endl;
}