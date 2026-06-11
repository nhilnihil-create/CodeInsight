#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

struct Edge {
    int to;
    int id;
};
using Graph = vector<vector<Edge>>;

Graph G;
int max_color = 0;
vector<int> parent, color, ans;
vector<vector<int>> child;

void dfs(int v) {
    int cnt = 0;
    for (auto e : G[v]) {
        if (e.to != parent[v]) {
            ++cnt;
            if (cnt == color[v]) ++cnt;
            parent[e.to] = v;
            child[v].push_back(e.to);
            ans[e.id] = cnt;
            color[e.to] = cnt;
            max_color = max(max_color, cnt);
            dfs(e.to);
        }
    }
}

int main() {
    int N;
    cin >> N;
    G = Graph(N);
    parent = vector<int>(N, -1);
    color = vector<int>(N, 0);
    ans = vector<int>(N - 1, 0);
    child = vector<vector<int>>(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    dfs(0);
    cout << max_color << endl;
    rep(i, N - 1) cout << ans[i] << endl;
    return 0;
}
