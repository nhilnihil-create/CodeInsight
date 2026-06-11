#include <bits/stdc++.h>
#include <atcoder/all>
#define F first
#define S second
using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
ll Mod = 1000000007;
int main() {
  int N,Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    fw.add(i,a);
  }
  for (int i = 0; i < Q; i++) {
    int mode;
    cin >> mode;
    if (mode == 0) {
      int p; ll x;
      cin >> p >> x;
      fw.add(p,x);
    } else {
      int l,r;
      cin >> l >> r;
      ll ans = fw.sum(l,r);
      cout << ans << endl;
    }
  }
  return 0;
}