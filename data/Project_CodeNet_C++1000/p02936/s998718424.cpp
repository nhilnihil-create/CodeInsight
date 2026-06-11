#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int N = 2e5 + 10;

V<V<int>> tree(N);
V<ll> c(N);
V<ll> ans(N);

void dfs(int i, int src) {
  ans[i] += c[i];
  for (auto n : tree[i]) {
    if (n == src) continue;
    ans[n] += ans[i];
    dfs(n, i);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  V<int> a(n), b(n);

  rep(i, n - 1) cin >> a[i] >> b[i];

  V<int> pa(n + 1);
  rep(i, n - 1) {
    tree[a[i]].push_back(b[i]);
    tree[b[i]].push_back(a[i]);
  }

  rep(i, q) {
    int p, x;
    cin >> p >> x;
    c[p] += x;
  }

  dfs(1, -1);

  for (int i = 1; i <= n; i++) printf("%ld ", ans[i]);
  printf("\n");
}
