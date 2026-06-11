#include<bits/stdc++.h>
using namespace std ;

// Template START
#define endl "\n"
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
const int mod = (int)1e9 + 7 ;
template<class T>
auto matrix( int r, int c, T v ){
    return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
template<class T>
auto matrix( int o1, int o2, int o3, T v ){ 
    return vector<vector<vector<T>>>( o1, vector<vector<T>>( o2, vector<T>( o3, v ) ) ) ;
}
#define v vector
// Template END

int power( int x, int n ){
    if( n == 0 ) return 1 ;
    else if( n & 1 ) return ( x * power( (x*x) % mod, n / 2 ) ) % mod ;
    return power( (x*x) % mod, n / 2 ) % mod ;
}



signed main(){
    int x ; cin >> x ;
    string ans = "" ;
    while( x ){
        x-- ;
        int f = (x % 26)  ;
        ans = char('a' + f ) + ans ;
        x /= 26 ;
    }
    cout << ans ;
    return 0 ;   
}          