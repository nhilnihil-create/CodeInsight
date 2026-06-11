
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e18;
int inf = 1e9;
ll MOD = 1e9+7;

struct Dijkstra {
    struct Edge {
        ll to;
        ll c;
    };

    int V;
    vector<vector<Edge>> e;
    vector<ll> d;

    Dijkstra(int V): V(V) {
        e.resize(V);
        d.resize(V);
    }

    void add_edge(int from, int to, ll cost) {
        e[from].pb({to, cost});
    }

    void operator()(ll s) {
        priority_queue<Pll, vector<Pll>, greater<>> q;

        REP(i, V) d[i] = INF;
        d[s] = 0;
        q.push({0, s});

        while(!q.empty()) {
            Pll n = q.top(); q.pop();
            ll v = n.se;
            if (d[v] < n.fi) continue;

            REP(i, e[v].size()) {
                Edge cur = e[v][i];
                ll cost = d[v] + cur.c;
               if (d[cur.to] > cost) {
                    d[cur.to] = cost;
                    q.push({cost, cur.to});
                }
            }
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N, M;
    cin >> N >> M;

    Dijkstra graph(3 * N);

    REP(i, M) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph.add_edge(3 * u, 3 * v + 1, 1);
        graph.add_edge(3 * u + 1, 3 * v + 2, 1);
        graph.add_edge(3 * u + 2, 3 * v, 1);
    }

    int s, t;
    cin >> s >> t;
    --s; --t;

    graph(s * 3);
    print(graph.d[3 * t] == INF ? -1 : graph.d[3 * t] / 3);
    
}
