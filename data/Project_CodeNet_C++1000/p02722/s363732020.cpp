#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,ll>;
using Graph= vector<vector<P>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
  ll  n; cin>> n ;
  ll k=n-1 ;
  //n の約数
  vector<ll> a ;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0) {
      a.pb(i) ; 
      if(i*i!=n) a.pb(n/i) ;
  }
  }
  ll ans=0 ;
  a.pb(n) ;
  ll nd=n  ;
  for(ll v:a){
    nd=n ;
    while(nd%v==0){
      nd/=v ;
    }
   if(nd%v==1) ans++ ;
   
  }
  //cout<<ans<<endl ;
  //n-1の約数
 
   for(ll i=2;i*i<=k;i++){
    if(k%i==0){
     ans+=2 ;
     if(i*i==k) ans-- ;
    }
   }
  if(n!=2) ans++ ;
  cout<<ans<<endl ;
  return 0;
  }