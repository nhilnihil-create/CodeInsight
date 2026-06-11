#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        std::cin >> A >> B;
        v[i] = std::make_pair(A, B);
    }

    std::sort(v.begin(), v.end(), [](auto p1, auto p2) {
        return p1.second > p2.second;
    });

    int ans = 0;
    std::vector<int> table(M, M);
    for (int i = 0; i < N; i++) {
        int now = M - v[i].first;

        if (now < 0) continue;

        while (0 <= now) {
            if (table[now] == M) {
                ans += v[i].second;
                table[now] = now - 1;
                break;
            }
            now = table[now]--;
        }
    }
    std::cout << ans << "\n";
}