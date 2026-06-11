#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

/*
  ll n , m ;
  cin >> n >> m ;
  ll a , b , c ;
  cin >> a >> b >> c ;
  vector<ll> A(n) ;
  cout << "Yes" << endl ;
  cout << "No"  << endl ;
*/

int main(){
    string s ;
    cin >> s ;
    ll mod = 2019 ;
    reverse(s.begin(),s.end()) ;
    ll now = 0 ;
    ll ans = 0 ;
    ll p = 1 ;
    map<ll,ll> mp ;
    mp[0]++ ;
    rep(i,s.size()){
      ll keta = ( s[i] - '0' ) ;
      now = keta*p + now ;
      now %= mod ;
      ans += mp[now] ;
      mp[now]++;
      p *= 10  ;
      p %= mod ;
      //cout << now << endl ;
    }
    cout << ans << endl ;
}
