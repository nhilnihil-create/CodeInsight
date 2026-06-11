#include <atcoder/fenwicktree>
#include <cstdio>

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  atcoder::fenwick_tree<long long> tree(n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    tree.add(i, a);
  }

  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);

    if (t == 0) {
      tree.add(l, r);
    } else if (t == 1) {
      printf("%lld\n", tree.sum(l, r));
    }
  }
  return 0;
}
