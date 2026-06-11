#include<bits/stdc++.h>
using namespace std;
#include<math.h>
#define ll long long
#define ld long double
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
 int main()
{
  Summon_Tourist
  //freopen("input.txt" , "r" , stdin ) ;
  ll h1,m1,h2,m2,k;
  cin>>h1>>m1>>h2>>m2>>k;
  ll x = ( h2 - h1 )*60 +( m2 - m1 ) ;
  ll ans = x - k ;
  cout<<ans;
  return 0;

}
