#include<atcoder/dsu>
#include<iostream>
using namespace std ;
using namespace atcoder ;

int main(){
  int n,q ;
  cin >> n >> q ;
  dsu d(n) ;
  while(q--){
    int t,u,v ;
    cin >> t >> u >> v ;
    if(t) cout << (d.same(u,v)?1:0) << endl ;
    else d.merge(u,v) ;
  }
}