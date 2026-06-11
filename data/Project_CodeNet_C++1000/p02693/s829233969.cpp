#include<bits/stdc++.h>
using namespace std;
#define M_PI  3.1415926535
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
// -----------------------------------------------CKMKB-----------------------------------------------------------
// -----------------------------------------------PKMKB-----------------------------------------------------------
ll n,k;
ll check( ll x , ll y ) { return (x<n && y<n); }
vector<pair<ll,ll > > func( ll r , ll c )
{
    vector<pair<ll,ll > > temp ;
    while( check(r,c) )
    {
        temp.push_back( make_pair(r,c) ) ;
        r++;c++;
    }
    return temp;
}
 int main()
{
  Summon_Tourist
  //freopen("input.txt" , "r" , stdin ) ;
  ll t = 1;
  //cin>>t;
  while(t--)
  {
        ll k,a,b;
        cin>>k>>a>>b;
        ll c ;
        if( a%k != 0)
        c = k - (a%k) ;
        else c = 0 ;
        if( a + c <=b ) cout<<"OK\n";
        else cout<<"NG\n";
  }
  return 0;

}
