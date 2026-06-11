#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int N, Q;
  cin >> N >> Q;
  
  dsu uf(N);
  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;
    
    if (t) cout << uf.same(u, v) << endl;
    else uf.merge(u, v);
  }
  
  return 0;
}