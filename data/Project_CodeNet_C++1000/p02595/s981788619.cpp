#include<bits/stdc++.h>
using namespace std ;
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
const int inf = (int)1e18 ;
void mxz( int &a, int b ){
	a = max( a, b ) ;
}

signed main(){
	double N, D ; cin >> N >> D ;
	int cnt = 0 ;
	double x, y ;
	set<pair<double,double>> st ;
	for( int i = 0 ; i < N ; i++ ){
		cin >> x >> y ;
		if( !present(st, make_pair(x,y)) ) if( sqrt( x*x + y*y ) <= (D) ) cnt++ ;
	}
	cout << cnt ;
	return 0 ;
}
