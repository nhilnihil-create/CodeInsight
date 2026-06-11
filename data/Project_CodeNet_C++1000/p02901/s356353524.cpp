#include <iostream>
#include <vector>

const int INF = 1 << 30;

int main() {
    int N, M;
    std::cin >> N >> M;

    int K = 1 << N;

    std::vector<int> dp(K, INF);
    dp[0] = 0;

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;

        int x = 0;
        for (int j = 0; j < b; j++) {
            int c;
            std::cin >> c;
            x += 1 << --c;
        }

        for (int j = K - 1; j >= 0; j--) {
            dp[j | x] = std::min(dp[j | x], dp[j] + a);
        }
    }

    std::cout << (dp[K - 1] == INF ? -1 : dp[K - 1]) << "\n";
}