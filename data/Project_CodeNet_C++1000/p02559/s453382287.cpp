#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int N, Q;
  cin >> N >> Q;
  
  fenwick_tree<long long> bit(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    bit.add(i, a);
  }
  
  while (Q--) {
    int t;
    cin >> t;
    
    if (t) {
      int l, r;
      cin >> l >> r;
      cout << bit.sum(l, r) << endl;
    } else {
      int p, x;
      cin >> p >> x;
      bit.add(p, x);
    }
  }
  
  return 0;
}