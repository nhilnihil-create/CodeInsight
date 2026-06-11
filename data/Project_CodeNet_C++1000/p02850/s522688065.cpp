//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


using Edge = pair<int, int>;  //(頂点番号, 辺番号)
using Graph = vector<vector<Edge>>;

Graph g;
int N;
vector<int> ans;


void dfs(int v, int p, int c) {
    int color = 1;
    for (auto e : g[v]) {
        if (e.first == p) continue;
        if (color == c) color++;
        ans[e.second] = color;
        dfs(e.first, v, color);
        color++;
    }
}


void solve() {
    cin >> N;
    g.resize(N);
    ans.resize(N-1);

    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }

    int num = 0;
    for (auto e : g) num = max(num, (int)e.size());

    dfs(0, -1, -1);

    cout << num << endl;
    for (auto v : ans) cout << v << endl;
}


int main() {
    solve();
    return 0;
}