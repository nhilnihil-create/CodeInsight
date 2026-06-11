#include <bits/stdc++.h>
using namespace std;

#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define ALL( a )        (a).begin(), (a).end()             

int solve( int n ) {
	if( n == 1 ) return 1;
	
	int cnt = 0;
	for( int i = n + 1; i <= 2 * n; i++ ) {
		if( i == 3 ) cnt++;
		else if( i % 2 != 0 ) {
			for( int j = 2; j <= sqrt( i ); j++ ) {
				if( i % j == 0 ) break;
				if( j == static_cast<int>( sqrt( i ) ) ) cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int n;

	while( 1 ) {
		cin >> n; if( n == 0 ) break;
		cout << solve( n ) << endl;

	}

}
