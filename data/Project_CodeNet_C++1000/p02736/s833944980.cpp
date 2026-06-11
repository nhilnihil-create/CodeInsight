#include <cstdio>

#define Int register int

const int MAXN = 1e6;
int n;
char s[MAXN + 5];

inline void Work () {
	scanf ( "%d %s", &n, s + 1 );
	for ( Int i = 1; i <= n; ++ i ) s[i] ^= '1';
	bool ex1 = false;
	for ( Int i = 1; i <= n && ! ex1; ex1 |= s[i ++] & 1 );
	for ( Int i = 1; i <= n; ++ i ) {
		if ( ex1 ) s[i] &= 1;
		else s[i] >>= 1;
	}
	int Cnt = 0;
	for ( Int i = 1; i <= n; ++ i ) ( Cnt += s[i] * ( n - 1 == ( ( i - 1 ) | ( n - i ) ) ) ) &= 1;
	printf ( "%d\n", Cnt << ( ex1 ^ 1 ) );
}

int main () {
	Work ();
	return 0;
}
