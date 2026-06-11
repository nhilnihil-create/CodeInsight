#include <atcoder/dsu>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  atcoder::dsu dsu(n);
  while (q--) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);

    if (t == 0) {
      dsu.merge(u, v);
    } else if (t == 1) {
      printf("%d\n", (int) dsu.same(u, v));
    }
  }  
  return 0;
}
