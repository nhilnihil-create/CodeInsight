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

int inv( int x ){
	return power( x, mod - 2 ) ;
}
const int mxn = (int)1e6 ;

signed main(){
	int n ; cin >> n ;
	vector<int> a(n) ;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i] ;
	}
	int cnt[mxn + 1] = {0} ;
	for( int i = 0 ; i < n ; i++ ){
		cnt[a[i]]++ ;
	}
	int ans = n ;
	for( int i = 0 ; i < n ; i++ ){
		bool ok = true ;
		for( int j = 1 ; j * j <= a[i] ; j++ ){
			if( a[i] % j == 0 ){
				if( j == 1 && a[i] != 1 ){
					int f = a[i] ;
					if( cnt[f] > 1 || cnt[1] > 0 ){
						ok = false ;
						break ;
					}
				}
				else if( j == 1 && a[i] == 1 ){
					if( cnt[1] > 1 ){
						ok = false ;
						break ;
					}
				}
				else {
					int f = j ;
					int s = a[i] / j ;
					if( cnt[f] > 0 || cnt[s] > 0 ){
						ok = false ;
						break ;
					}
				}
			}
		}
		if( !ok ) --ans ;
	}
	cout << ans ;
	return 0 ;
}











