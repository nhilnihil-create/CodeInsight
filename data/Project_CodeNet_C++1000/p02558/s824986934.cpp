#include <cstdio>

#include <atcoder/dsu>

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  atcoder::dsu dsu(n);
  for (int i = 0; i < q; ++i) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);

    if (t == 0) {
      dsu.merge(u, v);
    } else if (t == 1) {
      printf("%d\n", dsu.same(u, v)? 1: 0);
    }
  }
}
