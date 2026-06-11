#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i,n) {
    int a;
    cin >> a;
    fw.add(i,a);
  }
  rep(i,q) {
    int t;
    cin >> t;
    if(t) {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l,r) << endl;
    } else {
      int p, x;
      cin >> p >> x;
      fw.add(p,x);
    }
  }
  return 0;
}