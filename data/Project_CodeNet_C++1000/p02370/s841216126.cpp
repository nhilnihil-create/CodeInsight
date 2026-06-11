#include <iostream>
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
    vector<int> ord(n), indeg(n);
    for(auto &es : g) for(auto &e : es) indeg[e.dst]++;
    queue<int> q;
    for(int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    int k = 0;
    while(q.size()){
        int v = q.front(); q.pop();
        ord[k++] = v;
        for(auto &e : g[v]) {
            indeg[e.dst]--;
            if(indeg[e.dst] == 0) q.push(e.dst);
        }
    }
    return ord;
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