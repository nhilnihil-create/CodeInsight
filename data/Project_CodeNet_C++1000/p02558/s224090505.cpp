#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int N,Q;
  cin >> N >> Q;
  dsu D(N);
  
  for(int i=0;i<Q;i++){
    int t,u,v;
    cin >> t >> u >> v;
    if(t==0){
      D.merge(u,v);
    }
    if(t==1){
      if(D.same(u,v)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}
