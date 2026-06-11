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
  ll a , b, v , w, t;
  cin>>a>>v>>b>>w>>t;
  ll d = abs( a - b );
  ll c = (v-w)*t;
  cout<<( c>=d ? "YES" : "NO" );



  return 0;

}
