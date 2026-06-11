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
 
 ll dp[3005][3005] ;
 ll ep[3005][3005] ;

 int main(){
 ll n,t ; cin>>n>> t ;
 vector<ll> A(n),B(n) ;
 rep(i,n) cin>>A[i]>>B[i] ;
 rep(i,3005){
   dp[0][i]=0 ;
   ep[0][i]= 0;
 }
 
 rep(i,n){
   rep(j,3005){
    if(j>=A[i]) dp[i+1][j]= max(dp[i][j-A[i]]+B[i],dp[i][j]) ;
    else dp[i+1][j]= dp[i][j] ;

    if(j>=A[n-1-i]) ep[i+1][j]=max(ep[i][j-A[n-1-i]]+B[n-1-i],ep[i][j]) ;
    else ep[i+1][j]= ep[i][j] ;

   }
 }
 
 ll ans= 0 ;

 rep(i,n){
  rep(j,t){
    chmax(ans, dp[i][j]+ep[n-1-i][t-1-j]+B[i]) ;
  }
 }

 cout<<ans<<endl ;

   return 0 ;
 }

