#include <bits/stdc++.h>
using Weight = int;
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }


std::vector<int> tsort(const Graph &g) {
    int n = g.size();
    enum { YET, VISITED, DONE };
    std::vector<int> res, flg(n, YET);
    static const std::function<bool(int)> dfs = [&](int v) {
        if(flg[v] == VISITED)
            return false;
        else if (flg[v] == YET) {
            flg[v] = VISITED;
            for (auto &e : g[v])
                if (!dfs(e.dst)) return false;
            flg[v] = DONE;
            res.push_back(v);
        }
        return true;
    };
    for (int i = 0; i < n; ++i)
        if (flg[i] == YET && !dfs(i)) return {};
    std::reverse(res.begin(), res.end());
    return res;
}

using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int s,t;
        cin >> s >> t;
        g[s].emplace_back(s,t,0);
    }
    vector<int> ord = tsort(g);
    for(int i = 0; i < n; ++i){
        cout << ord[i] << '\n';
    }
}