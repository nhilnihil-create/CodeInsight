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
int power( int x, int n ){
    if( n == 0 ) return 1 ;
    else if( n & 1 ) return ( x * power( (x*x) % mod, n / 2 ) ) % mod ;
    return power( (x*x) % mod, n / 2 ) % mod ;
}
// Template END


const int mxn = (int)1e7 ;

signed main(){
	int n ; cin >> n ;
	int ans3 = 0, lmt ;
	for( int j = 1 ; j <= n ; j++ ){
		lmt = n / j ;
		ans3 += ( ( lmt * ( lmt + 1 ) ) * j ) / 2 ;
	}
	
	cout << ans3 ;
	return 0 ;
}











