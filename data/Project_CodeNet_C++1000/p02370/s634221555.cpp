#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(const vector<vector<int>> &G){
    vector<int> res, visited(G.size());
    auto dfs = [&](auto &&dfs, int cur) {
        if(visited[cur]++) return;
        for(auto &to : G[cur]) {
            if(!visited[to]) dfs(dfs, to);
        }
        res.emplace_back(cur);
    };
    for(int i = 0; i < G.size(); ++i) {
        dfs(dfs, i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for(int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
    }
    auto list = topologicalSort(G);
    for(auto &p : list) cout << p << '\n';
    return 0;
}

