# include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std ;
int N = 3e5 + 7 ;
ll N1 = 1e9 + 7 ;
int main( ){
    speed ;
    ll TJK = 1 ;
    // cin >> TJK ;
    while( TJK -- ){
        ll n ;
        cin >> n ;
        ll u = 0 ;
        for( ll i = 0 ; i < 64 ; i ++ ){
            if( n >= pow( 2 , i ) ){
                u = i ;
            }else{
                break ;
            }
        }
        ll ans = 0 ;
        for( int i = 0 ; i <= u ; i ++ ){
            ans += pow( 2 , i ) ;
        }
        cout << ans << endl ;
    }
}
