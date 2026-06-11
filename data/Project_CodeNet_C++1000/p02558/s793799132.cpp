#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, q;
  cin >> n >> q;
  dsu d(n);
  rep(i,q) {
    int t, u, v;
    cin >> t >> u >> v;
    if(t == 0) d.merge(u,v);
    else cout << (d.same(u,v) ? 1 : 0) << endl;
  }
  return 0;
}
