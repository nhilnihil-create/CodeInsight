// AOJ 0521
#include<cstdio>
#define rep(i,a) for( int i = 0; i != (a); ++i )

const int C[6] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	int p;
	while( scanf( "%d", &p ), p )
	{
		p = 1000-p;

		int ans = 0;
		rep( i, 6 )
			ans += p/C[i], p %= C[i];

		printf( "%d\n", ans );
	}

	return 0;
}