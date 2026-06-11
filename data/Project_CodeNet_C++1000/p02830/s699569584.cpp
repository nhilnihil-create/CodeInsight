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

char s[ 110 ], t[ 110 ];

int main() {
	int n;
	scanf( "%d", &n );
	scanf( "%s%s", s, t );
	for( int i = 0; i < n; ++i )
		printf( "%c%c", s[ i ], t[ i ] );
	return 0;
}