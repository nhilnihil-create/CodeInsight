#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 110;
int _w;

int n, k, change[N], c1, c0;
char s[N];

int solve1() {
	int ans = 0;
	for( int i = 2; i <= n; ++i ) {
		if( s[i] == s[i-1] ) {
			change[i] = true;
			++i;
			++ans;
		}
	}
	return c1 = ans;
}

int solve2() {
	memset(change, 0, sizeof change);
	s[0] = s[n];
	int ans = 0;
	for( int i = 1; i <= n; ++i ) {
		if( s[i] == s[i-1] ) {
			change[i] = true;
			++i;
			++ans;
		}
	}
	return c0 = ans;
}

ll solve() {
	solve1();
	if( change[n] ) {
		return ll(k) * c1;
	} else {
		solve2();
		if( change[n] ) {
			return c0 * ll(k/2) + c1 * ll(k-k/2);
		} else {
			return c1 + ll(k-1) * c0;
		}
	}
}

int main() {
	_w = scanf( "%s", s+1 );
	n = (int)strlen(s+1);
	_w = scanf( "%d", &k );
	printf( "%lld\n", solve() );
	return 0;
}
