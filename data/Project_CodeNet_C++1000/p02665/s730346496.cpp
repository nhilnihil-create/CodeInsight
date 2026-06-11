#include <bits/stdc++.h>

const std::int64_t INF = 1e18;

int main() {
    std::int32_t N; std::cin >> N;
    std::vector<std::int64_t> A(N + 1), B(N + 1);
    for (std::int32_t i = 0; i <= N; ++i) {
        std::cin >> A[i];
    }
    // if (N == 0) {
    //     if (A[0] == 1) std::cout << 1 << std::endl;
    //     else std::cout << -1 << std::endl;
    //     return 0;
    // }
    // if(A[0] != 0) {
    //     std::cout << -1 << std::endl;
    //     return 0;
    // }
    B[N] = A[N];
    for (std::int32_t i = N - 1; i >= 0; --i) {
        B[i] = B[i + 1] + A[i];
    }
    B[0] = 1;
    for (std::int32_t i = 1; i <= N; ++i) {
        B[i] = std::min(B[i], 2 * (B[i - 1] - A[i - 1]));
    }
    std::int64_t ans = 0;
    for (std::int32_t i = 0; i <= N; ++i) {
        if (B[i] < A[i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans += B[i];
    }
    std::cout << ans << std::endl;
    return 0;
}
