// AOJ ITP 1_5_A
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
				putchar( '#' );
			puts("");
		}
		puts("");
	}

	return 0;
}