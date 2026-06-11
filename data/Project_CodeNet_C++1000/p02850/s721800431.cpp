#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#else
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
 public:
  vector<pi> V[maxn];
  int n, ans, pt[maxn];
  void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      V[u].emplace_back(v, i);
      V[v].emplace_back(u, i);
    }
    dfs(1, 1, 0);
    cout << ans << '\n';
    for (int i = 1; i < n; ++i) {
      cout << pt[i] << "\n";
    }
  }
  void dfs(int u, int f, int fp) {
    int a = 1;
    for (auto v : V[u]) {
      if (v.first == f)
        continue;
      if (a == fp)
        a++;
      pt[v.second] = a;
      ans = max(ans, a);
      dfs(v.first, u, a++);
    }
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}