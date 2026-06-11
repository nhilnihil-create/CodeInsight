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
  ll n;
  cin>>n;
  vector<ll> a(n+1),sum(n+1);
  for(ll i = 0 ; i<=n ; i++ ) { cin>>a[i];}
  sum[n] = a[n] ;
  for( ll i=n-1 ; i>=0 ; i--) { sum[i] = sum[i+1]+ a[i] ;}
  ll last = 1 ; ll ans = 1;
  if( (n==0 && a[0]!=1) || (n>0 && a[0]!=0) ) { cout<<-1; return 0;}
  for( ll i = 1 ; i<=n ; i++ )
  {
      ll poss = last*2 ;
      if( a[i] > poss  ) { cout<<-1; return 0 ; }
      ll acc = sum[i];
      ll temp = min( poss , acc ) ;
      ans += temp ;
      last = temp - a[i] ;
  }
  cout<<ans;
  return 0;

}
