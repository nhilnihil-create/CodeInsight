#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

int main() {
    int N, K;
    std::cin >> N >> K;

    int sum_A = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum_A += A[i];
    }

    std::priority_queue<int> que;
    for (int i = 1; i * i <= sum_A; i++) {
        if (sum_A % i) continue;

        que.push(i);
        if (sum_A / i != i) que.push(sum_A / i);
    }

    while (!que.empty()) {
        int x = que.top();
        que.pop();

        std::vector<long long> v(N), w(N);
        for (int i = 0; i < N; i++) {
            v[i] = A[i] % x;
            w[i] = x - A[i] % x;
        }

        std::sort(v.begin(), v.end());
        std::sort(w.begin(), w.end(), std::greater<int>());

        for (int i = 0; i < N - 1; i++) {
            v[i + 1] += v[i];
            w[i + 1] += w[i];
        }

        for (int i = 0; i < N; i++) {
            if (v[i] <= K && v[i] == w[N - 1] - w[i]) {
                std::cout << x << "\n";
                return 0;
            }
        }
    }
}