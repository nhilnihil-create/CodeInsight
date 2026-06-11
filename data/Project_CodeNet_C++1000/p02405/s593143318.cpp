// AOJ ITP 1_5_C
#include<cstdio>
#define rep(i,a) for( int i = 0; i != (a); ++i )

int main()
{
	int H, W;
	while( scanf( "%d%d", &H, &W ), H|W )
	{
		rep( i, H )
		{
			rep( j, W )
				putchar( i&1 ? (j&1 ? '#' : '.') : (j&1 ? '.' : '#') );
			puts("");
		}
		puts("");
	}

	return 0;
}