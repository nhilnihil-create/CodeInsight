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
int main()
{
  Summon_Tourist
  //freopen("input.txt" , "r" , stdin ) ;
  ll t = 1;
  //cin>>t;
  while(t--)
  {
      string s,t ;
      cin>>s>>t ;
      ll ans = inf ;
      for( ll i= 0 ; i<(s.length()-t.length()+1) ; i++ ){
        ll temp = 0 ;
        for( ll j = i ; j<i+t.length(); j++ ){
            if( s[j] != t[j-i] ) temp++ ;
        }
        ans = min( ans , temp ) ;
      }
      cout<<ans<<endl;

  }
return 0;


}
