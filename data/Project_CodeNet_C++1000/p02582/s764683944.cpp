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

 
signed main(){
	string s ; cin >> s ;
	int len = s.size() ;
	int mx = 0 ;
	for( int i = 0 ; i < len ; i++ ){
		int cnt = 0 ;
		if( s[i] == 'R' ){
			cnt = 1 ;
			int j = i + 1 ;
			while( j < len && s[j] == 'R' ){
				cnt++ ;
				j++ ;
			}
			i = j - 1 ;
			mx = max( mx, cnt ) ;
		}
	}
	cout << mx ;
	return 0 ;
}
  
