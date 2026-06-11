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

int main() {
	ll n, m;
	ll ans = 0;
	scanf( "%lld", &n );
	if( n & 1 ) {
		printf( "0" );
		return 0;
	}
	n >>= 1;
	m = 5;
	while( n >= m ) {
		ans += n / m;
		m *= 5;
	}
	printf( "%lld", ans );
	return 0;
}