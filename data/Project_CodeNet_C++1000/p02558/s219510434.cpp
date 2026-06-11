#include <atcoder/dsu>
#include <cstdio>

int main() {
  int n, q, t, u, v;
  scanf("%d%d", &n, &q);

  atcoder::dsu ds(n);
  while (q--) {
    scanf("%d%d%d", &t, &u, &v);
    if (t)
      printf("%d\n", ds.same(u, v));
    else
      ds.merge(u, v);
  }
  return 0;
}