// AOJ ITP 1_5_B
#include<cstdio>
#define rep(i,a) for( int i = 0; i != (a); ++i )

int H, W;

int main()
{
	while( scanf( "%d%d", &H, &W ), H|W )
	{
		rep( i, W )
			putchar('#');
		puts("");
		rep( t, H-2 )
		{
			putchar('#');
			rep( i, W-2 )
				putchar('.');
			putchar('#');
			puts("");
		}
		rep( i, W )
			putchar('#');
		puts(""); puts("");
	}

	return 0;
}