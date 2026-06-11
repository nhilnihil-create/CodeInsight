#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // bfs
    int N, M;
    cin >> N >> M;
    vector<int> graph[N]; // 0-indexed
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dir(N, -1);
    dir[0] = 0;
    queue<P> que;
    auto push = [&] (int x, int step) {
        que.emplace(x, step);
        return;
    };
    que.emplace(0, 0);
    while (!que.empty()) {
        auto p = que.front(); que.pop();
        int cur = p.first, step = p.second;
        for (int next : graph[cur]) {
            if (dir[next] != -1) continue;
            dir[next] = cur;
            push(next, step+1);
        }
    }
    rep(i, N) {
        if (dir[i] == -1) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 1; i < N; i++) {
        cout << dir[i] + 1 << '\n';
    }
    return 0;
}