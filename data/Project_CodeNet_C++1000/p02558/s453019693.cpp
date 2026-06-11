#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  dsu uf(N);
  rep(query, Q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) uf.merge(u, v);
    else {
      if (uf.same(u, v)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}