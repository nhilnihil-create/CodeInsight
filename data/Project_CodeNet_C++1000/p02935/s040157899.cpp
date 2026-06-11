#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    double sum = (v[0] + v[1]) / 2.0;
    for (int i = 2; i < N; i++) {
        sum = (sum + v[i]) / 2.0;
    }

    std::cout << sum << std::endl;

    return 0;
}