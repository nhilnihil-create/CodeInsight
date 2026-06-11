#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;
const int MOD = 1e9 + 7;

signed main(){

  int n, q; cin >> n >> q;
  dsu uf(n);
  for(int i = 0; i < q; i++){
    int t, u, v; cin >> t >> u >> v;
    if(t == 0){
      uf.merge(u, v);
    }else{
      cout << uf.same(u, v) << endl;
    }
  }

  return 0;
}