#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

#define INF 1001001001
#define MAX 200005

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i,n) {
    int x; cin >> x;
    fw.add(i,x);
  }
  vector<ll> ans;
  rep(i,q) {
    int t;
    cin >> t;
    if (t==0) {
      int p, x; cin >> p >> x;
      fw.add(p,x);
    } else {
      int l, r; cin >> l >> r;
      ans.push_back(fw.sum(l,r));
    }
  }
  for (auto a : ans) cout << a << endl;

  return 0;
}
