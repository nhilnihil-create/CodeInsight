#include <utility>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main( void ) {

	int n, m, d, p, i, ans, guarded;
	pair<int,int> pd[10000];
	
	while ( scanf( "%d %d", &n, &m ) && ( n != 0 || m != 0 ) ) {
	
		ans = 0;
	
		for ( i = 0; i < n; i++ ) {
		
			scanf( "%d %d", &d, &p );
			pd[i] = make_pair( p, d );
		
		}
		
		sort( pd, pd + n );
		reverse( pd, pd + n );
	
		for ( i = 0; i < n; i++ ) { ans += pd[i].first * pd[i].second; }
		
		for ( i = 0; i < n && m > 0; i++ ) {
		
			guarded = min( m, pd[i].second );
			ans -= pd[i].first * guarded;
			m -= guarded;
			
		}
		
		printf( "%d\n", ans );
	
	}

	return 0;

}