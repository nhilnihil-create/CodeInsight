#include <iostream>
#include <vector>
#include <deque>
using i64 = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::vector<int> done(n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        int c = 0;
        std::deque<int> q { i };
        done[i] = 1;
        while (!q.empty()) {
            const int v = q.front();
            q.pop_front();
            c++;
            for (const int to : g[v]) {
                if (!done[to]) {
                    done[to] = 1;
                    q.push_back(to);
                }
            }
        }
        if (c > ret) ret = c;
    }

    std::cout << ret << std::endl;

    return 0;
}
