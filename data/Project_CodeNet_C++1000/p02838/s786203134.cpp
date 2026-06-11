#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

const ll mod = 1e9 + 7 ;

int main(){
    ll n     ;
    cin >> n ;
    vector<ll> A(n) ;
    rep(i,n) cin >> A.at(i) ;
    ll ans = 0 ;
    rep(i,60){
        ll x = 0 ;
        rep(j,n) if( A.at(j) >> i & 1 )x++ ;
        ll tem = x*(n-x) ;
        tem %= mod ;
        rep(j,i){
            tem *= 2 ;
            tem %= mod ;
        }
        ans += tem ;
        ans %= mod ;
    }
    cout << ans << endl ;
}