#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << (x) << endl

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
    enum State { NEW, ACTIVE, FINISHED };
    std::vector<int> res;
    vector <State> state(n, NEW);
    static const std::function<bool(int)> dfs = [&](int v) {
        state[v] = ACTIVE;
        for (auto &e : g[v]) {
            int w = e.dst;
            if (state[w] == ACTIVE) return false;
            else if (state[w] == NEW) if (!dfs(w)) return false;
        }
        state[v] = FINISHED;
        res.push_back(v);
        return true;
    };
    for (int i = 0; i < n; ++i)
        if (state[i] == NEW && !dfs(i)) return {-1};
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
