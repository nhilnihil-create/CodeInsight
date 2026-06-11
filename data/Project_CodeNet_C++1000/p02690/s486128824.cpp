#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

ll fac5( ll n, ll t ){
  if( t == 0 ) return 1;
  ll tmp = fac5(n,t/2);
  if( t%2 == 0 ){
    return tmp*tmp;
  }else{
    return tmp*tmp*n;
  }
}

int main(){
  ll x;cin >> x;
  for(ll i=-1000;i<=1000;++i){
    for(ll j=-1000;j<=1000;++j){
      if( fac5(i,5) - fac5(j,5) == x ){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}