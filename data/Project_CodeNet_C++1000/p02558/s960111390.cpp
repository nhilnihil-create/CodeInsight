#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  dsu d(n);
  rep(i,q) {
    int t, u, v;
    cin >> t >> u >> v;
    if(t == 0) d.merge(u, v);
    else{
      if(d.same(u, v)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}