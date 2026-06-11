#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
  
  
  int n,q; cin>>n>>q;
  atcoder::dsu d(n);
  while(q--){
    int t,u,v; cin>>t>>u>>v;
    if(t==0){
      d.merge(u,v);
    }
    else{
      cout<<d.same(u,v)<<endl;
    }
  }
  
}
