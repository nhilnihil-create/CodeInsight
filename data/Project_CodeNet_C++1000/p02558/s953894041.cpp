#include <atcoder/all>
#include <bits/stdc++.h>
typedef long long int lld;
typedef unsigned long long int llu;
#define INF (lld)(9223372036854775807)
#define IINF (int)(2147483647)

using namespace std;
using namespace atcoder;

int main(void) {
  lld n, q;
  cin >> n >> q;
  dsu d(n);

  for (lld i = 0; i < q; i++) {
    lld t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.merge(u, v);
    } else {
      if (d.same(u, v)) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }
}
