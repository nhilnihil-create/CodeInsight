#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>; 
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
 ll n,m ;
 cin>> n>>m ;
 vector<ll> A(n) ; rep(i,n) cin>>A[i] ;
 ll sum= 0 ; rep(i,n) sum+= A[i] ;
 priority_queue<ll>  hiki ;
 rep(i,n){
 hiki.push(A[i]) ;
 }
 ll ans=0 ;
 rep(i,m){
  ll x= hiki.top() ;
  hiki.pop() ;
  ans+= x-(x/2) ;
  hiki.push(x/2) ;
  
 }
 
  cout<<sum-ans<<endl ;
  return 0;
  }