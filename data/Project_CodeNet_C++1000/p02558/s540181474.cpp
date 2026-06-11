#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  cin >> n >> q;
  dsu d(n);
  while(q--){
    int op,u,v;
    cin >> op >> u >> v;
    if(op == 0){
      d.merge(u,v);
    }
    else{
      if(d.same(u,v)) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
  }
  return 0;
}