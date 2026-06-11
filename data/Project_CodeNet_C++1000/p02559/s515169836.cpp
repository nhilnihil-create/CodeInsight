#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define ll long long

int main(void){
  int N, Q;
  cin >> N >> Q;
  fenwick_tree<ll> bit(N);
  for (int i = 0; i < N; ++i){
    int ai; cin >> ai;
    bit.add(i, ai);
  }
  while (Q--){
    int q; cin >> q;
    if (q == 0){ // add query
      int p, x; cin >> p >> x;
      bit.add(p, x);
    }
    else{ // get sum query
      int l, r; cin >> l >> r;
      cout << (bit.sum(l, r)) << endl;
    }
  }
  return 0;
}