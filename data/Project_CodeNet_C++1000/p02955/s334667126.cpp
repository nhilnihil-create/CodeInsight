#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
 ll n,k ;cin>>n>>k ;
 vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
 ll all = 0;
 rep(i,n) all+= A[i] ;
 vector<ll> div ;
 for(ll i=1;i*i<=all ;i++){
   if(all%i==0){
     div.pb(i) ;
     div.pb(all/i) ;
   }
 }
  ll ans=0 ;
  for(ll u :div){
   vector<ll> B(n) ;
   ll sum=0 ;
   rep(i,n){
   B[i]= A[i]%u  ;
   sum+= B[i] ; 
   }
  ll ko= sum/u ;
  sort(B.begin(),B.end()) ;
  ll rem=0 ;
  rep(i,n-ko){
  rem+=B[i] ;
  }
  if(rem<=k) chmax(ans,u) ;
  }
  cout<<ans<<endl ;
  return 0;
  }