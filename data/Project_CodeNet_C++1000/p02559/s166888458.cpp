#include <iostream>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  ll n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  for (int i = 0; i < n; i++) {
    ll ai; cin >> ai;
    fw.add(i, ai);
  }

  while (q--) {
    ll qq, l, r;
    cin >> qq >> l >> r;
    if (qq == 0) {
      fw.add(l, r);
    } else if (qq == 1) {
      cout << fw.sum(l, r) << endl;
    }
  }
  
}
