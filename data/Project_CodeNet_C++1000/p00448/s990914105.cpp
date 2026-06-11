// AOJ 0525
#include<algorithm>
#include<cstdio>
#define rep(i, a) for( int i = 0; i != (a); ++i )

bool fld[10][10000];

int main()
{
	int R, C;
	while( scanf( "%d%d", &R, &C ), R | C )
	{
		rep( i, R )
			rep( j, C )
				scanf( "%d", &fld[i][j] );
	
		int ans = 0;
		for( int i = 1; i != 1 << R; ++i )
		{
			int cnt = 0;
			for( int c = 0; c != C; ++c )
			{
				int cn = 0;
				for( int r = 0; r != R; ++r )
					cn += (fld[r][c])^(i>>r&1);

				cnt += std::max( cn, R-cn );
			}
			ans = std::max( ans, cnt );
		}

		printf( "%d\n", ans );
	}

	return 0;
}