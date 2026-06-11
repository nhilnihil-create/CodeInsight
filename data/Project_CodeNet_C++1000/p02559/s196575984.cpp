#include <bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  for(int i = 0; i < n; i++) {
    ll y;
    cin >> y;
    fw.add(i, y);
  }
  for(int i = 0; i < q; i++) {
    bool num;
    cin >> num;
    if(!num) {
      int p;
      ll x;
      cin >> p >> x;
      fw.add(p, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << endl;
    }
  }
}