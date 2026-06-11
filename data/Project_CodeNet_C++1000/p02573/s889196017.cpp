#include<bits/stdc++.h>
using namespace std;
#define M_PI  3.1415926535
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define Summon_Tourist ios::sync_with_stdio(false);cin.tie(0);
ll gcd(ll a , ll b) { return b==0?a: gcd( b, a%b); }
ll lcm(ll a , ll b) { return a/gcd(a,b) * b ; }
ll inf = 1e9 + 7;
ll modexp( ll base ,ll power)
 {
     if( power == 0  ) return 1;
     if( power & 1) return base*modexp( base , power-1 )%inf;
     return modexp(base*base%inf,power/2);
 }
 vector<ll> a[200005] ;
 vector<ll> visited(200005,0),weights(200005,1) ;
 ll dfs( ll x) {
   if( visited[x] ) return 0 ;
   visited[x] = 1 ;
   ll ret = weights[x] ;
   for( auto it : a[x] ) { if(visited[it]) continue ; ret += dfs(it) ; }
   return ret ;
    }
int main()
{
  Summon_Tourist
  //freopen("input.txt" , "r" , stdin ) ;
  ll t = 1;
  //cin>>t;
  while(t--)
  {
     ll n,m;
     cin>>n>>m;
     for( ll i = 0 ; i<m ; i++ ){
        ll x,y ;
        cin>>x>>y;
        a[x].push_back(y) ;
        a[y].push_back(x) ;
     }
    ll ans = -1 ;
    for( ll i = 1 ; i<=n ; i++ ){
        if( visited[i] != 1 ) {  ll ret = dfs(i) ; ans = max( ans , ret ); }
    }
    cout<<ans<<endl;

  }
return 0;


}
