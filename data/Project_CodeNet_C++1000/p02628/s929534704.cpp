#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K, N, ans = 0;
    std::cin >> N >> K;
    std::vector<int> p(N);
    for(int i = 0; i < N; i++) {
        std::cin >> p.at(i);
    }

    std::sort(p.begin(), p.end());

    for(int i = 0; i < K; i++) {
        ans += p.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}
