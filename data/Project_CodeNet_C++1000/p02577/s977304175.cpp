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
int mod = (int)1e9 + 7 ;
#define inf (int)1e18
/************************************************************/


signed main(){
	string s ; cin >> s ;
	int len = s.size() ;
	int sum = 0 ;
	for( int i = 0 ; i < len ; i++ ){
		sum += ( s[i] - '0' ) ;
	}
	cout << ( sum % 9 == 0 ? "Yes" : "No" ) ;
	return 0 ;
}