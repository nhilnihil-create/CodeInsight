/*
    Author:zeke

    pass System Test!
    GET AC!!
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
// cout << "Case #" << index << " :IMPOSSIBLE";

typedef ll Weight;
struct Edge {  // src:辺の始点,dst:辺の終点,weight:辺の重さ
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight)
        : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight
                                :  //辺は重さが重いものを"小さい"と定義する
               e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
//引数
//g:隣接リスト,s:始点,dist:各頂点までの距離が入る,prev:最短路木の親頂点が入る
//戻値 なし
void shortestPath(const Graph &g, int s, vector<Weight> &dist,
                  vector<int> &prev) {
    int n = g.size();
    dist.assign(n, INF);
    dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q;
    Q.push(Edge(-2, s, 0));
    while (!Q.empty()) {
        Edge e = Q.top();
        Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;
        for (auto f = g[e.dst].begin(); f != g[e.dst].end(); f++) {
            if (dist[f->dst] > e.weight + f->weight) {
                dist[f->dst] = e.weight + f->weight;
                Q.push(Edge(f->src, f->dst, e.weight + f->weight));
            }
        }
    }
}

//引数 prev:最短路木の親頂点集合,t:終点
//戻値 path:sからtへの最短経路
vector<int> buildPath(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u]) path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    ll n,m;
    cin>>n>>m;
    Graph g(3*n);
    rep(i,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        rep(j,3){
            ll start=u*3+j;
            ll dist=v*3+(j+1)%3;
            //cout<<start<<" "<<dist<<endl;
            g[start].push_back(Edge(start,dist,1));
        }
    }
    ll s,t;
    cin>>s>>t;
    vector<Weight> dist;
    vector<int> prev;
    shortestPath(g,(s-1)*3+2, dist, prev);
    if(dist[3*t-1]==INF){
        cout<<-1<<endl;
        return 0;
    }
    cout << dist[3 *t  - 1] /3<< endl;
}
