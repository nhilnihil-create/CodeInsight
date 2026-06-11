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
  ll x ;
  cin >> x ; 
  for(ll a = -1000 ; a <= 1000 ; a++ ){
    for(ll b = -1000 ; b <= 1000 ; b++ ){
      if( a*a*a*a*a - b*b*b*b*b == x ){
        cout << a << ' ' << b << endl ;
        return 0 ;
      }
    }
  }
}
