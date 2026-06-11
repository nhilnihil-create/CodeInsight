#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

struct Edge{
    // 始点, 終点, 重み, 最大量
    long long src, dst, weight, capacity;
    Edge(): src(0), dst(0), weight(0), capacity(0) {}
    Edge(long long s, long long d, long long w): src(s), dst(d), weight(w) {}
    Edge(long long s, long long d, long long w, long long c): src(s), dst(d), weight(w), capacity(c) {}
};

class Graph{
public:
    long long size;
    vector<vector<Edge>> node;
    Graph(long long n): size(n), node(n) {}
    // 無向辺の追加
    void addEdge(long long s, long long d, long long w = 1){
        node[s].emplace_back(s, d, w);
        node[d].emplace_back(d, s, w);
    }
    // 有向辺の追加
    void addArc(long long s, long long d, long long w = 1){
        node[s].emplace_back(s, d, w);
    }
    // ノードの追加
    void addNode(){
        size++;
        node.emplace_back();
    }
};

// Dijkstra(Heap); 単一始点最短路（優先度付きキューを利用したダイクストラ法）
// ：負辺がある場合はループにハマる可能性があるため、Bellman-Fordを使うこと。[O((E+V)logV)]
vector<long long> Dijkstra(const Graph &g, long long src){
    const long long WeightINF = numeric_limits<long long>::max()/2-1;
    using state = pair<long long, long long>;
    priority_queue<state> que;
    vector<long long> d(g.size, WeightINF);
    d[src] = 0;
    que.emplace(0, src);
    while(!que.empty()){
        auto p = que.top(); que.pop();
        long long w = -p.first;
        long long v = p.second;
        if(d[v] < w) continue;
        for(auto &edge: g.node[v]){
            if(d[edge.dst] > d[v] + edge.weight){
                d[edge.dst] = d[v] + edge.weight;
                que.emplace(-d[edge.dst], edge.dst);
            }
        }
    }
    return d;
}

int main(){
    Init();
    ll n, m; cin >> n >> m;
    Graph g(3*n);

    rep(i, m){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        g.addArc(3*u+0, 3*v+1, 1);
        g.addArc(3*u+1, 3*v+2, 1);
        g.addArc(3*u+2, 3*v+0, 1);
    }
    ll s, t; cin >> s >> t; s--; t--;
    s *= 3; t *= 3;
    auto dij = Dijkstra(g, s);
    cout << (dij[t]%3 == 0 ? dij[t]/3 : -1) << endl; 
}