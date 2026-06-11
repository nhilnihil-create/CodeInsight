#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll l , r ;
    cin >> l >> r ;
    for(ll i = 1 ; 2019 * i <= 2 * 1e9 ; i++ ){
        if( l <= 2019*i && 2019*i <= r ){
            cout << 0 << endl ;
            return 0 ;
        }
    }
    ll ans = 2 * 1e10 ;
    for(ll i = l ; i < r ; i++ ){
        for(ll j = i+1 ; j <= r ; j++ ){
            ll tem = i*j ;
            tem %= 2019 ;
            ans = min(tem,ans) ;
        }
    }
    cout << ans <<endl ; 
}