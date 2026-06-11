#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
template<class T> void out(T a){cout<<a<<'\n';}

int main(){
  int n,q;
  cin>>n>>q;
  dsu d(n);
  rep(i,q){
    int k,u,v;
    cin>>k>>u>>v;
    if(k==0) d.merge(u,v);
    else out(d.same(u,v));
  }
}
