#include <atcoder/dsu.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> t(Q), u(Q), v(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> t[i] >> u[i] >> v[i];
  }

  dsu d(N);
  for (int i = 0; i < Q; ++i) {
    if (t[i] == 0) {
      d.merge(u[i], v[i]);
    } else {
      cout << d.same(u[i], v[i]) << endl;
    }
  }
}
