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
	int n ; cin >> n ;
	string s ; cin >> s ;
	int len = s.size() ;
	int left = 0, right = len - 1, cnt = 0 ;
	while( left < right ){
		if( s[right] == 'R' ) {
			if( s[left] != 'W' ) ++left ;
			else ++cnt, ++left, --right ;
		}		
		else {
			if( s[left] == 'W' ){
				--right ;
			}
			else{
				++left, --right; 
			}
		}
	} 
	cout << cnt ;
	return 0 ;
}
