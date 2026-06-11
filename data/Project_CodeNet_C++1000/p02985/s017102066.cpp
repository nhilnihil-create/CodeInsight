#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

void dfs(vector<vector<ll>>&tree, ll place, ll from, ll k, ll depth, ll&ans) {
  if (ans == -1) ans = k;
  depth++;
  ll j = 0;
  for (int i = 0; i < tree[place].size(); i++) {
    ll nx = tree[place][i];
    if (from == nx) continue;
    if (depth < 2) ans = (ans * (k-1-j)) % MOD;
    else ans = (ans * (k-2-j)) % MOD;
    j++;
    dfs(tree, nx, place, k, depth, ans);
  }
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  ll n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << k << endl;
    return 0;
  }
  vector<vector<ll>> tree(n);
  for (int i = 0; i < n-1; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    tree[a].emplace_back(b);
    tree[b].emplace_back(a);
  }
  ll root;
  for (int i = 0; i < n; i++) if (tree[i].size() == 1) root = i;

  ll ans = -1;
  dfs(tree, root, -1, k, 0, ans);
  cout << ans << endl;
}
