#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

ll sumn(ll n) {
  return (n * (n + 1)) / 2;
}

struct SegmentTree {
  vector<ll> tree, lazy;

  void push(int node, int x, int y, ll val) {
    tree[node] += val * (y - x);
    lazy[node] += val;
  }
  void split(int node, int x, int y) {
    int z = (x + y) / 2;

    push(2 * node, x, z, lazy[node]);
    push(2 * node + 1, z, y, lazy[node]);

    lazy[node] = 0;
  }
  void merge(int node) {
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  int sz;
  SegmentTree(int n) {
    for (sz = 1; sz < n; sz <<= 1);
    tree.resize(2 * sz, 0);
    lazy.resize(2 * sz, 0);
  }

  void update(int l, int r, ll val, int node = 1, int x = 0, int y = -1) {
    if (y == -1) y = sz;
    if (l >= y || r <= x) return;
    if (l <= x && y <= r) {
      push(node, x, y, val);
      return;
    }
    split(node, x, y);
    update(l, r, val, 2 * node, x, (x + y) / 2);
    update(l, r, val, 2 * node + 1, (x + y) / 2, y);
    merge(node);
  }

  ll query(int l, int r, int node = 1, int x = 0, int y = -1) {
    if (y == -1) y = sz;
    if (l >= y || r <= x) return 0;
    if (l <= x && y <= r) {
      return tree[node];
    }
    split(node, x, y);
    ll res = query(l, r, 2 * node, x, (x + y) / 2)
      + query(l, r, 2 * node + 1, (x + y) / 2, y);
    merge(node);
    return res;
  }
};

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<VI> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    adj[u].push_back(v);
  }

  ll ans = 0;
  SegmentTree tree(n + 1);
  for (int u = n; u >= 1; u--) {
    for (int v: adj[u]) {
      tree.update(v, n + 1, 1);
    }
    ll cur = sumn(n - u + 1) - tree.query(u, n + 1);
    ans += cur;
  }
  cout << ans << endl;


  return 0;
}
