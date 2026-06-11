#include<bits/stdc++.h>
using namespace std ;

main(){
	int x,y,s ;
	while( cin >> x >> y >> s , x ){
		int ans = 0 ;
		for( int i=1 ; i<s ; i++ ){
			for( int j=1 ; j+i<=s ; j++ ){
				double A = i*(100.0+x) / 100 ;
				double B = j*(100.0+x) / 100 ;
				int c = A , d = B ;
				if( c+d == s ){
					A = i*(100.0+y) / 100 ;
					B = j*(100.0+y) / 100 ;
					c = A ; d = B ;
					ans = max( ans , c+d ) ;
				}
			}
		}
		cout << ans << endl ;
	}
}