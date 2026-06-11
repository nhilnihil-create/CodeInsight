#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
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
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){
 ll n,m ; cin>>n>>m ;
 vector<P> key ;
 rep(i,m){
     ll a,b ; cin >>a>> b;
     ll sum= 0;
     rep(i,b){
         ll c ;cin>>c ;
        c-- ;
        sum = sum | 1<< c ;
     }
     key.eb(sum,a) ;
 }
 vector<ll> dp(1<<n,INF) ;
 dp[0]=0 ;
 rep(i,1<<n){
     rep(j,m){
         dp[i| key[j].fi] = min( dp[i|key[j].fi],
         dp[i]+key[j].se) ;
     }
 }
 ll ans= dp.back() ;
 if(ans== INF) cout<<-1<<endl ;
 else cout<<ans<<endl ;
 return 0 ; 
}

