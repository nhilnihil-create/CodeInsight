#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> c(N + 1), v(N + 1);
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        ++v[++c[A]];
    }

    for (int i = 0; i < N; i++) v[i + 1] += v[i];
    for (int i = 1; i <= N; i++) v[i] /= i;

    int x = N;
    for (int i = 1; i <= N; i++) {
        while (x > 0 && v[x] < i) x--;
        std::cout << x << "\n";
    }
}