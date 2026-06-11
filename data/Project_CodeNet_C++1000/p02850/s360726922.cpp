# include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using Edge = pair<int,int>; // (隣接頂点, 辺番号)
using Graph = vector<vector<Edge>>;
int N;
Graph G;

int main() {
    cin >> N;
    G.assign(N, vector<Edge>());
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].emplace_back(b, i); 
        G[b].emplace_back(a, i);
    }
    int max_color = 0;
    for (int i = 0; i < N; ++i) chmax(max_color, (int)G[i].size());
    vector<int> res(N-1, -1);

    vector<int> dist(N, -1);
    queue<pair<int,int>> que; // (頂点, 前回の色)
    que.push({0, -1});
    dist[0] = 0;
    while (!que.empty()) {
        auto p = que.front(); que.pop();
        int v = p.first, c = p.second;
        int color = 1;
        if (color == c) ++color;
        for (auto e : G[v]) {
            if (dist[e.first] == -1) {
                dist[e.first] = dist[v] + 1;
                que.push({e.first, color});
                res[e.second] = color;
                ++color;
                if (color == c) ++color;
            }
        }
    }
    cout << max_color << endl;
    for (auto v : res) cout << v << endl;
}