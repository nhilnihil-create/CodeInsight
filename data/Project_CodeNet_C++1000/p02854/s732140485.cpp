#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {
 
  ll N ;
  ll ans = 1e18 ;
  cin >> N ;
  vector<ll> A(N) ;
  rep(i,N) cin >> A.at(i) ;
  ll full = 0 ;
  ll part = 0 ;
  rep(i,N) full += A.at(i) ;
  rep(i,N-1){
    part += A.at(i) ;
    full -= A.at(i) ;
    ans = min( abs(full - part) , ans ) ;
    //cout << ans << endl;
  }
  cout << ans << endl;
}