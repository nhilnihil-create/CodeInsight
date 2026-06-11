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

ll gcd( ll, ll );

int main() {
	ll x, y;
	scanf( "%lld%lld", &x, &y );
	printf( "%lld", x * y / gcd( x, y ) );
	return 0;
}

ll gcd( ll x, ll y ) {
	return y? gcd( y, x % y ): x;
}