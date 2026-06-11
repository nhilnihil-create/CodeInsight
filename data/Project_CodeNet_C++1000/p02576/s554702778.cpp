#include<bits/stdc++.h>
using namespace std ;

/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
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
/************************************************************/


signed main(){
	float N, X, T ;
	cin >> N >> X >> T ;
	cout << int(ceil(N/X) * T) ;
	return 0 ;
}