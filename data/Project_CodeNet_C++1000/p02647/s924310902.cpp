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
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for( ll i = 0 ; i<n ; i++ ) cin>>a[i];
  vector<ll> ans;
  if( k <= 50 )
  {
      for( ll i = 0 ; i<k ; i++ )
      {
          vector<ll> b(n,0);
          for( ll i = 0 ; i<n ; i++ )
          {
              ll x = max( 0ll , i - a[i] );
              ll y = min( n-1 , i + a[i] );
              b[x]++;
              if( y+1<n ) b[y+1]--;
          }
          for( ll i = 1 ; i<n ; i++ ) b[i]+=b[i-1];
          a = b;
      }
      for( ll i = 0 ; i<n ; i++ )
        cout<<a[i]<<" ";
  }
  else
  {
      for( ll i = 0 ; i<n ; i++ )
        cout<<n<<" ";
  }

  return 0;

}
