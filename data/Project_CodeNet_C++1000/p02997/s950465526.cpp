#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int M = N * (N - 1) / 2 - K;

    if (M < N - 1) {
        std::cout << "-1\n";
        return 0;
    }

    std::cout << M << "\n";

    for (int i = 2; i <= N; i++)
        std::cout << 1 << " " << i << "\n";

    int count = N - 1;
    for (int i = 2; i <= N - 1; i++)
        for (int j = i + 1; j <= N; j++) {
            if (M <= count)
                break;
            std::cout << i << " " << j << "\n";
            count++;
        }
}