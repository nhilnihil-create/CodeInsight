#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
#define ALL(a)  (a).begin(),(a).end()

int main(){
  ll x ;
  cin >> x ;
  ll start = 100 ;
  for( ll i = 1 ; ; i++ ){
    start = start + start/100 ;
    if( start >= x ){
      cout << i << endl ;
      return 0 ;
    }
  }
}