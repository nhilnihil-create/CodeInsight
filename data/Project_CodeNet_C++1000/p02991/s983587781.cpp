#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{ for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{ os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{ cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int n, m;

int en(int v, int i) {
    return i * n + v;
}

pii de(int x) {
    int v = x % n;
    int i = x / n;
    return {v, i};
}

void solve() {
    cin >> n >> m;
    vector<int> G[n * 3];
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[en(u, 0)].push_back(en(v, 1));
        G[en(u, 1)].push_back(en(v, 2));
        G[en(u, 2)].push_back(en(v, 0));
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    vector<int> dist(3 * n, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int v = pq.top().se;
        pq.pop();
        for (auto u : G[v]) {
            if (chmin(dist[u], dist[v] + 1)) {
                pq.push({dist[u], u});
            }
        }
    }
    cout << (dist[t] == INF ? -1 : dist[t] / 3) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
