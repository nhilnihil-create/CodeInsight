#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
// 深さ優先探索
vector<bool> seen;  // 探索したか記録
int t=0;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    t++;
    for (auto e : G[v]) {
        if (!seen[e.to]) {  // 訪問済みでなければ探索
            dfs(G, e.to);
        }
    }
}
int main() {
    int n, m,ans=0;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    seen.assign(n, false);  // 初期化
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(G, i);
            if(ans<t){
                ans=t;
            }
            t=0;
        }
    }
    cout << ans << endl;
    return 0;
}