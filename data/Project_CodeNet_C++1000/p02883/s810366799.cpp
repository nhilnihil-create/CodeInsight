#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 

 int main(){
  ll n,k ; cin>>n>>k ;
  vector<ll> A(n),B(n) ;
  rep(i,n) cin>>A[i] ;
  rep(i,n) cin>>B[i] ;
  sort(A.begin(),A.end()) ;
  sort(B.rbegin(),B.rend()) ;

  vector<ll> sum(n) ;
  ll end=0 ;
  ll big=0 ;
  rep(i,n){
     sum[i]=A[i]*B[i] ;
     big+= A[i] ;
   chmax(end,sum[i]) ;
  }

  ll l=0 ; ll r= end ;

  while(r-l>1){
    ll m = (r+l)/2 ;
    ll res= 0 ;
    rep(i,n){
      if(m<sum[i]) res+= (sum[i]-m+B[i]-1)/B[i] ;
    }
    if(res<=k) r=m ;
    else l=m ;
  }
  if(big<=k) cout<<0<<endl ;
  else cout<<r<<endl ;
  

   return 0 ;
 }

