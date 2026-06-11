#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using ll=long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=k;i<(ll)(n);i++)
template<class T> void out(T a){cout<<a<<'\n';}

int main(){
  int n,q;
  cin>>n>>q;
  fenwick_tree<ll> ft(n);
  rep(i,n){
    int x; cin>>x;
    ft.add(i,x);
  }
  rep(i,q){
    int k; cin>>k;
    if(k==0){
      int p,x;
      cin>>p>>x;
      ft.add(p,x);
    }
    else{
      int l,r;
      cin>>l>>r;
      out(ft.sum(l,r));
    }
  }
}
