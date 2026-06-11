#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;
int _w;

int C( int n, int m ) {
	return (n|m) == n;
}

int n, a[N], cnt[3];
char s[N];

int main() {
	cin >> n;
	cin >> (s+1);
	for( int i = 1; i <= n; ++i ) {
		a[i] = s[i] - '0' - 1;
		++cnt[a[i]];
	}
	if( cnt[1] == 0 ) {
		for( int i = 1; i <= n; ++i )
			if( a[i] == 2 )
				a[i] = 1;
	} else {
		for( int i = 1; i <= n; ++i )
			if( a[i] == 2 )
				a[i] = 0;
	}
	int ans = 0;
	for( int i = 1; i <= n; ++i )
		ans = (ans + a[i] * C(n-1, i-1)) & 1;
	if( cnt[1] == 0 ) ans *= 2;
	printf( "%d\n", ans );
	return 0;
}
