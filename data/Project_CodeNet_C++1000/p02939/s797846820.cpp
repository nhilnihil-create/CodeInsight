#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x7f
#define MAX_INF_VAL 0x7f7f7f7f
#define pi 3.141592653589
#define eps 1e-6
//#define p 2173412051LL
//#define sz 2

using namespace std;

char s[ 200010 ];
int f[ 2 ][ 200010 ];

int main() {
	int n;
	scanf( "%s", s + 1 );
	n = strlen( s + 1 );
	for( int i = 1; i <= n; ++i ) {
		if( s[ i ] != s[ i - 1 ] )
			f[ 0 ][ i ] = max( f[ 0 ][ i ], f[ 0 ][ i - 1 ] + 1 );
		if( i > 1 )
			f[ 0 ][ i ] = max( f[ 0 ][ i ], f[ 1 ][ i - 1 ] + 1 );
		if( i > 1 )
			f[ 1 ][ i ] = max( f[ 1 ][ i ], f[ 0 ][ i - 2 ] + 1 );
		if( i > 2 && ( s[ i - 3 ] != s[ i - 1 ] || s[ i - 2 ] != s[ i ] ) )
			f[ 1 ][ i ] = max( f[ 1 ][ i ], f[ 1 ][ i - 2 ] + 1 );
	}
	printf( "%d", max( f[ 0 ][ n ], f[ 1 ][ n ] ) );
	return 0;
}