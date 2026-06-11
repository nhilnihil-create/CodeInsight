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
const int inf = (int)1e18 ;
/************************************************************/

// i -> P[i]
// with cost C[P[i]]

signed main(){
	int N, K ; cin >> N >> K ;
	vector<int> P(N+1), C(N+1) ;
	for( int i = 1 ; i <= N ; i++ ) cin >> P[i] ;
	for( int i = 1 ; i <= N ; i++ ) cin >> C[i] ;
	int ans = -inf ;
	for( int i = 1 ; i <= N ; i++ ){
		int cycleSum = 0 ;
		int cycleLen = 0 ;
		int v = i ;
		while( true ) {
			cycleLen++ ;
			cycleSum += C[P[v]] ;
			if( P[v] == i ) break ;
			v = P[v] ;
		}
		v = i ;
		cycleSum = max( 0LL, cycleSum ) ;
		int partialSum = 0 ;
		int cnt = 0 ;
		while( true ){
			cnt++ ;
			partialSum += C[P[v]] ;
			int num = ( K - cnt ) / cycleLen ;
			ans = max(ans, partialSum + cycleSum * num ) ;
			if( P[v] == i ) break ;
			v = P[v] ;
			if( cnt >= K ) break ;
		}
	}
	cout << ans ;
	return 0 ;
}
