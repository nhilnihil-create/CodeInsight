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
  ll n , p ; cin>>n >> p;
  string s ; cin>> s ;
  ll ans=0 ;
  
  if(p==2 || p==5 ){
    rep(i,n){
      int x= s[i]-'0' ;
      if(x%p==0){
        ans += i+1 ;
       }
    } 
  }
  else{
   vector<ll> sum(n+1) ; 
   vector<ll> keta(n) ;
   rep(i,n){
     if(i==0) keta[i]=1 ;
     else{
       keta[i]= (keta[i-1]*10) %p ;
     }
   }
  sum[0]=0 ;
  rep(i,n){
    int x = s[n-1-i]-'0' ;
    sum[i+1]= (sum[i]+x*keta[i]) % p ;
  }
  map<ll,ll> mp ;
  rep(i,n+1){
    mp[sum[i]]++ ;
  }
  for(auto u : mp){
    ll y= u.se ;
    ans += y*(y-1)/2 ;
  }

  }
  cout<<ans<<endl ;
   return 0 ;
 }