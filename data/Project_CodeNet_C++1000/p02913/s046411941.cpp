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
  ll n ; cin>> n ;
  string s ; cin>> s ;
  ll dp[n+1][n+1] ;
  rep2(i,1,n-1){
    if(s[i-1]==s[n-1]) dp[n][i]=1 ;
    else dp[n][i]=0 ;
  }
 
  rep3(i,n-1,2){
    rep2(j,1,i-1){
      if(s[i-1]==s[j-1]) dp[i][j]=dp[i+1][j+1]+1 ;
      else dp[i][j]=0 ;
    }
  }
 ll ans=0 ;
  rep2(i,2,n){
    rep2(j,1,i-1){
      chmax(ans,min(dp[i][j],i-j)) ;
    }
  }
  cout<<ans<<endl ;
   return 0 ;
 }

