#include<bits/stdc++.h>
using namespace std ;
 
/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
const int inf = (int)1e9 ;
/************************************************************/

bool diff( vector<int> a ){
	int len = a.size() ;
	sort( all(a) ) ;
	for( int i = 0 ; i < len - 1 ; i++ ){
		if( a[i+1] == a[i] ){
			return false ;
		}
	}
	return true ;
}
bool check( int &a, int &b, int &c ){
	return ( a + b > c && b + c > a && c + a > b ) ;
} 

 
signed main(){
	int n ; cin >> n ;
	vector<int> a(n) ;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i] ;
	}
	int cnt = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = i + 1 ; j < n ; j++ ){
			for( int k = j + 1 ; k < n ; k++ ) {
				vector<int> temp = { a[i], a[j], a[k] } ;
				if( diff( temp ) && check( a[i], a[j], a[k] ) ){
					cnt++ ;
				}
			}
		}
	}
	cout << cnt ;
	return 0 ;
}
  
