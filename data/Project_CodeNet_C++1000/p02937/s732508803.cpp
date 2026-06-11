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
  string s ,t ;
  cin >>s>>t ;
  ll k = s.size() ;
  ll len = t.size() ;
  vector<vector<ll>> mp(26) ;
  rep(i,k){
    ll  a= s[i]-'a' ;
    mp[a].pb(i) ;
  }
  ll now=0 ;
  bool ok=0;
  

  rep(i,len){
    ll p= now%k ;
    ll unti =t[i]-'a' ;
    
    if(mp[unti].empty()){
      ok=1 ;
      break ;
    } 
    auto itr = lower_bound(mp[unti].begin(),mp[unti].end(),p) ;
    if(itr==mp[unti].end()){
      now= now-p+mp[unti][0]+k+1 ;
    }
    else{
      ll q= itr-mp[unti].begin() ;
    now = now-p+mp[unti][q]+1 ;
    }
    //cout<<now<<endl ;
  }
   if(ok) cout<<-1<<endl ;
   else cout<<now<<endl ;
  
   return 0 ;
 }

