#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int n, q;

int main() {
  cin >> n >> q;
  dsu d(n);
  while (q--) {
    int cmd, u, v;
    scanf("%d %d %d", &cmd, &u, &v);
    if (cmd) {
      printf("%d\n", (int) d.same(u, v));
    } else {
      d.merge(u, v);
    }
  }
  return 0;
}

