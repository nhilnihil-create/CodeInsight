#include <atcoder/all>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll digitcal(ll x){
  ll n=0;
  while(x>0){
    x/=10;
    n++;
  }
  return n;
}

int main() {
  int n,q;
  cin>>n>>q;
  dsu d(n);
  for(int i=0;i<q;i++){
    int t,u,v;
    cin>>t>>u>>v;
    if(t==0){
      d.merge(u,v);
    }
    else{
      cout<<d.same(u,v)<<endl;
    }
  }
  return 0;
}
