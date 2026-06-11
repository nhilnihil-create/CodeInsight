#include<bits/stdc++.h>
using namespace std ;

// Template START
#define endl "\n"
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
const int mod = (int)1e9 + 7 ;
#define vv(T) vector<vector<T>>
#define vvv(T) vector<vector<vector<T>>>
template<class T>
auto matrix( int r, int c, T v ){
    return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
template<class T>
auto matrix( int o1, int o2, int o3, T v ){ 
    return vector<vector<vector<T>>>( o1, vector<vector<T>>( o2, vector<T>( o3, v ) ) ) ;
}
// Template END

int power( int x, int n ){
    if( n == 0 ) return 1 ;
    else if( n & 1 ) return ( x * power( (x*x) % mod, n / 2 ) ) % mod ;
    return power( (x*x) % mod, n / 2 ) % mod ;
}
int ans = 0 ;
signed main(){
    int n ; cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    sort( all(a), greater<int>() ) ;
    if( n == 2 ){
        cout << a[0] ;
        return 0 ;
    }
    for(int i = 1 ; i < n ; i++){
        ans += a[i/2] ;
    }
    cout << ans ;
    return 0 ;   
}
