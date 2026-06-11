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

// TopologicalSort; トポロジカルソート
// ：有向非巡回グラフ（DAG）の全ての辺が右向きになるように整列する。[O(E+V)]
vector<long long> TopologicalSort(const Graph &g){
    vector<long long> indegree(g.size), sorted;
    for(long long v=0; v<g.size; v++) for(auto &edge: g.node[v]) indegree[edge.dst]++;
    queue<long long> que;
    for(long long i=0; i<g.size; i++) if(indegree[i] == 0) que.push(i);
    while(!que.empty()){
        long long v = que.front();
        que.pop();
        sorted.emplace_back(v);
        for(auto &edge: g.node[v]) if (--indegree[edge.dst] == 0) que.push(edge.dst);
    }
    return *max_element(indegree.begin(), indegree.end()) == 0LL ? sorted : vector<long long>();
}

long long encode(long long i, long long j){
    if(i<j) swap(i, j);
    return i*(i-1)/2+j+1;
}

vi d(1000*999/2+1, 0);
vi seen(1000*999/2+1, 0);
long long dfs(Graph &g, ll now){
    if(seen[now] == 1) return d[now];
    for(auto &edge: g.node[now]) chmax(d[now], dfs(g, edge.dst)+1);
    seen[now] = 1;
    return d[now];
}

int main(){
    Init();
    ll n; cin >> n;
    Graph g(n*(n-1)/2+1);
    vi d(n*(n-1)/2+1, 0);
    rep(i, n){
        ll now = 0;
        rep(j, n-1){
            ll num;
            cin >> num;
            num--;
            ll next = encode(i, num);
            g.addArc(now, next);
            now = next;
        }
    }

    // 閉路判定
    auto p = TopologicalSort(g);
    ll cnt = 0;
    if(!p.size()) cnt = -1;
    // 閉路が無いなら最長距離を求める
    else cnt = dfs(g, 0);
    cout << cnt << endl;
}