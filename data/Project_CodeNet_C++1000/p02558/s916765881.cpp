#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int n,q;
  cin >> n >> q;
  dsu tree(n);
  while(q--){
    
    int t,u,v;
    cin >> t >> u >> v;
    if(t==0) tree.merge(u,v);
    else{
      if(tree.same(u,v)){
        cout << 1 << endl;
      }
      else{
        cout << 0 << endl;
      }
    }
  }
  return 0;
}