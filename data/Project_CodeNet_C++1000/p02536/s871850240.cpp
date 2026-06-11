#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, vector<bool> &seen, int v) {
    seen[v] = true;
    for (auto nv : G[v]) if (!seen[nv]) dfs(G, seen, nv);
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b), G[b].push_back(a);
    }
    int res = 0;
    vector<bool> seen(N, false);
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        else{
          dfs(G, seen, v);
          ++res;
        }
    }
    cout << res - 1 << endl;
}