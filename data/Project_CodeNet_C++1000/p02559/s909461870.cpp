#include <bits/stdc++.h>
using namespace std;
#include <atcoder/fenwicktree>
using namespace atcoder;
using ll = long long;
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)

int main() {
  int N, Q; cin >> N >> Q;
  fenwick_tree<ll> fw(N);
	rep(i, N) {
		ll a; cin >> a;
		fw.add(i, a);
	}
  while (Q--) {
    int q; cin >> q;
    if (q == 0) {
      int p; ll x; cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r; cin >> l >> r;
      cout << fw.sum(l, r) << endl;
    }
  }
}