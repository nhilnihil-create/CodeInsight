//
// Created by Ellen7ions on 2020/9/28.
//

#include <iostream>
#define oo 0x7fffff

namespace MyNameIsLzz {

    int N, M, X;

    int map[15][15];
    int C[15];
    int val[15];
    int ans = oo;

    void dfs(int cur, int sum) {
        if (cur == N) {
            for (int i = 0; i < M; i++)
                if (val[i] < X)
                    return;
            ans = std::min(ans, sum);
            return;
        }
        for (int i = 0; i < M; i++) val[i] += map[cur][i];
        dfs(cur + 1, sum + C[cur]);
        for (int i = 0; i < M; i++) val[i] -= map[cur][i];

        dfs(cur + 1, sum);
    }

    void solve() {
        std::cin >> N >> M >> X;
        for (int i = 0; i < N; i++) {
            std::cin >> C[i];
            for (int j = 0; j < M; j++) std::cin >> map[i][j];
        }
        dfs(0, 0);
        if (ans != oo)
            std::cout << ans << std::endl;
        else
            std::cout << -1 << std::endl;
    }
}
int main() {
    MyNameIsLzz::solve();
    return 0;
}