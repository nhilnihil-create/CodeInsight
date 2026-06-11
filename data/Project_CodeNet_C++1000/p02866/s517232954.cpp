#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
int n;
int d[120000];
int ex[120000] , mx;
long long ans;
long long ksm ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 ) s = s * f % mod;
		f = f * f % mod; x = x / 2;
	}
	return s % mod;
}
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &d[i] );
		ex[d[i]]++;
		mx = max ( mx , d[i] );
	}
	ans = 1;
	if ( d[1] != 0 ) ans = 0;
	if ( ex[0] != 1 ) ans = 0;
	for ( i = 1 ; i <= mx ; i++ ) {
		ans = ans * ksm ( ex[i-1] , ex[i] ) % mod;
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}
