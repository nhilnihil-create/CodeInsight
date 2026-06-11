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
 
 ll dp[20010] ;
 int main(){
ll h,n ; cin>>h>>n ;
vector<P> A(n) ;
rep(i,n) cin>>A[i].fi>>A[i].se ;
dp[0]=0 ;
rep2(i,1,20005){
  ll now=INF ;
  rep(j,n){
   if(i-A[j].fi>=0){
    chmin(now,dp[i-A[j].fi]+A[j].se) ;
   }
  }
  dp[i]= now ;
}
ll ma= 0 ;
rep(i,n) chmax(ma,A[i].fi) ;
ll ans=INF ;
rep2(i,h,h+ma) chmin(ans,dp[i]) ;
cout<<ans<<endl ; 
   return 0 ;
}

