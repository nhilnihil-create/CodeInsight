#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;

int main() {
    cin >> n;
    vector<pii> edges;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.emplace_back(a, b);
    }

    int k = -1;
    map<pii, int> color;
    vector<int> cs(n, 0);

    vector<bool> visited(n, 0);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        int t = g[u].size();
        chmax(k, t);
        int c = 1;
        for (const auto &v: g[u]) {
            if (visited[v]) continue;
            if (c == cs[u]) c++;
            visited[v] = true;
            cs[v] = color[make_pair(u, v)] = color[make_pair(v, u)] = c++;
            q.emplace(v);
        }
    }

    cout << k << endl;
    for (const auto &e: edges) cout << color[e] << endl;
}
