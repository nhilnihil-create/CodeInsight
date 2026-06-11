#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

using Weight = int;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

vector<int> tsort(const Graph &g){
    int n = g.size();
    vector<int> res, vis(n);
    function<bool(int)> dfs = [&](int v){
        vis[v] = true;
        for(auto &e : g[v]) if(!vis[e.dst] && !dfs(e.dst)) return false;
        res.push_back(v);
        return true;
    };
    for(int i = 0; i < n; ++i) if(!vis[i]) if(!dfs(i)) return {};
    reverse(res.begin(), res.end());
    return res;
}

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