#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

vector<vector<int>> G;
vector<bool> seen;
vector<int> ans;

void dfs(int v, int p = -1) {
  seen[v] = true;
  EACH(nv, G[v]) {
    if (seen[nv]) continue;
    if (nv == p) continue;
    ans[nv] += ans[v];
    dfs(nv, v);
  }
}

void solve(istream& cin, ostream& cout) {
  int n, q;
  cin >> n >> q;
  G.resize(n);
  seen.assign(n, false);
  ans.assign(n, 0);
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  REP(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0);
  REP(i, n) {
    cout << ans[i] << endl;
  }
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
