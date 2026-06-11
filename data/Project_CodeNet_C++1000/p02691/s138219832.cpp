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
    ll n ;
    cin >> n ;
    vector<ll> A(n) ;
    rep(i,n) cin >> A.at(i) ;
    ll count = 0 ;
    map<ll,ll> mp ;
    rep(i,n) mp[ A.at(i) + i + 1 ]++ ;
    rep(j,n) count += mp[(j+1) - A.at(j) ] ;
    cout << count << endl ; 
}
