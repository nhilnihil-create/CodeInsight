#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

template<typename T>
struct Bellman_Ford {
private:
    struct edge { int to; T cost; };
    int V; // 頂点数
    vector<vector<edge>> G;
    vector<T> d;
public:
    const T inf = numeric_limits<T>::max();

    Bellman_Ford(int V) : V(V){
        G.resize(V);
        d.resize(V);
    }

    // 有向辺を張る
    void add_edge(int from, int to, T cost) {
        G[from].push_back({to,cost});
    }

    // 頂点 s からの最短コストを d に入れる
    // sからたどり着く負閉路がある場合 False
    bool build(int s) {
        d.assign(V,inf);
        d[s] = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                for (edge e : G[j]) {
                    if (d[j] != inf && d[j] + e.cost < d[e.to]) {
                        d[e.to] = d[j] + e.cost;
                        if (i == V - 1) {
                            return false;
                        }
                    }
                }
            }
        }
        /*
        REP(i, V) {
            cout << s << " -> " << i << " = " << d[i] << endl;
        }
        */
        return true;
    }

    // s から v までの最短コスト
    // 行けない場合は inf
    T dist(int v) {
        return d[v];
    }
};

int main() {
    int v, e, s; cin >> v >> e >> s;
    Bellman_Ford<ll> G(v);
    REP(i, e) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        G.add_edge(a, b, c);
    }
    if (!G.build(s)) {
        puts("NEGATIVE CYCLE");
    }
    else {
        REP(i, v) {
            if (G.dist(i) == G.inf) {
                puts("INF");
            }
            else {
                printf("%lld\n", G.dist(i));
            }
        }
    }
    return 0;
}
