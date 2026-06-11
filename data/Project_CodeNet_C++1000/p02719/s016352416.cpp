#include <iostream>

int main() {
    int64_t N, K;
    std::cin >> N >> K;

    N %= K;
    int64_t ans = std::abs(K - N) < N ? std::abs(K - N) : N;
    std::cout << ans << std::endl;

    return 0;
}