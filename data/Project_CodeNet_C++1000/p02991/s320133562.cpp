#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
struct edge { ll to, cost; };

const int MAX_V =300000;
const ll INF = 1LL<<60;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i,G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int N, M, S, T;
    cin >> N >> M;
    V = N * 3;
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        G[u[i]].push_back({v[i] + N, 1});
        G[u[i] + N].push_back({v[i] + N + N, 1});
        G[u[i] + N + N].push_back({v[i], 1});
    }
    cin >> S >> T;
    S--;
    T--;
    dijkstra(S);
    if (d[T] == INF) cout << "-1\n";
    else cout << d[T] / 3 << endl;
    //rep(i, V) cout << i << " " << d[i] << endl;
}