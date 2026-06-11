#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int K, N;
    std::cin >> K >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> diff(N);
    for (int i = 0; i < N - 1; i++) {
        diff[i] = A[i+1] - A[i];
    }
    diff[N-1] = (K + A[0]) - A[N-1];

    std::sort(diff.begin(), diff.end(), std::greater<int>());

    int ans = std::accumulate(diff.begin() + 1, diff.end(), 0);
    std::cout << ans << std::endl;

    return 0;
}