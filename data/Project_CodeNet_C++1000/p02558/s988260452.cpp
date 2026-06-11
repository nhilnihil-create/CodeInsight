#include<bits/stdc++.h>
#include<atcoder/dsu>

using namespace std;
using namespace atcoder;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q;  cin >> n >> q;
  dsu d(n);
  while (q--){
    int tp, u, v; cin >> tp >> u >> v;
    if(tp==0) d.merge(u,v);
    else  cout << d.same(u,v) << "\n";
  }
  return 0;
}