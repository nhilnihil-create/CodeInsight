#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 1e5 + 1;
int n, m;
vector<int> g[N];
bitset<N> vis;

void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << endl;
  return 0;
}