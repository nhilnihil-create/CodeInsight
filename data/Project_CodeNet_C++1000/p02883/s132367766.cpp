#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    long long K;
    std::cin >> N >> K;

    std::vector<long long> A(N), F(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> F[i];

    std::sort(A.begin(), A.end());
    std::sort(F.begin(), F.end(), std::greater<long long>());

    long long left = 0, right = 1LL << 40;
    while (left < right) {
        long long x = (left + right) / 2;

        long long res = 0;
        for (int i = 0; i < N; i++) {
            res += std::max(0LL, A[i] - x / F[i]);
        }

        if (res <= K) {
            right = x;
        } else {
            left = x + 1;
        }
    }
    std::cout << right << "\n";
}