#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x3f
#define MAX_INF_VAL 0x3f3f3f3f
#define MAX_INF_VAL_LL 0x3f3f3f3f3f3f3f3f
#define pi 3.141592653589
#define eps 1e-6
//#define p 2173412051LL
//#define sz 2

using namespace std;

bool vis[ 4 ];

int main() {
	int a, b;
	scanf( "%d%d", &a, &b );
	vis[ a ] = vis[ b ] = true;
	for( int i = 1; i <= 3; ++i )
		if( !vis[ i ] ) {
			printf( "%d", i );
			return 0;
		}
	return 0;
}