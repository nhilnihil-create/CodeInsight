#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

struct edge{
    int to;
    ll cost;
};

vector<ll> dijkstra(vector<edge> g[], int s, int V) {

    vector<ll> dist(V, LINF);

    priority_queue<pll, vector<pll>, greater<pll>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        ll cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e: g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<edge> G[n];
    x--; y--;
    rep(i, n - 1) {
        G[i + 1].push_back({i, 1});
        G[i].push_back({i + 1, 1});
    }
    int cnt[2020] = {0};
    G[x].push_back({y, 1});
    G[y].push_back({x, 1});
    rep(i, n) {
        auto dist = dijkstra(G, i, n);
        REP(j, i + 1, n) cnt[dist[j]]++;
    }
    REP(i, 1, n) cout << cnt[i] << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
