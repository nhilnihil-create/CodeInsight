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
        int n ;
        cin >> n ;
        int a[n] ;
        for( int i = 0 ; i < n ; i ++ ){
            cin >> a[i] ;
        }
        ll ans = 0 ;
        for( int i = 1 ; i < n ; i ++ ){
            if( a[i] < a[i-1] ){
                ans += a[i-1] - a[i] ;
                a[i] += a[i-1] - a[i] ;
            }
        }
        cout << ans << endl ;
    }
}
