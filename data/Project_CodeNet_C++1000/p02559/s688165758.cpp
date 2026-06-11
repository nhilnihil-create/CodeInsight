#include <atcoder/fenwicktree>
#include <cstdio>
using ll = int64_t;
#define rep(i, j, n) for (size_t i = 0; i < (int)n; ++i)

int main() {
  int n, q, t;
  ll u, v;
  scanf("%d%d", &n, &q);
  atcoder::fenwick_tree<ll> ft(n);
  rep(i, 0, n) {
    scanf("%lld", &u);
    ft.add(i, u);
  }

  while (q--) {
    scanf("%d%lld%lld", &t, &u, &v);
    if (t)
      printf("%lld\n", ft.sum(u, v));
    else
      ft.add(u, v);
  }
  return 0;
}