// AOJ 2013 (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013)
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a) for(int i=0;i<(a);++i)
#define clr(a,v) memset((a),(v),sizeof(a))

const int MAX_H = 24, MAX_M = 60, MAX_S = 60;

int n;
int S[MAX_H*MAX_M*MAX_S];

int main()
{
	while( scanf( "%d", &n ), n )
	{
		clr( S, 0 );

		rep( i, n )
		{
			int hh, mm, ss;
			scanf( "%d:%d:%d", &hh, &mm, &ss );
			++S[hh*60*60+mm*60+ss];
			scanf( "%d:%d:%d", &hh, &mm, &ss );
			--S[hh*60*60+mm*60+ss];
		}

		int ans = S[0];
		rep( i, MAX_H*MAX_M*MAX_S-1 )
		{
			S[i+1] += S[i];
			ans = std::max( ans, S[i+1] );
		}

		printf( "%d\n", ans );
	}

	return 0;
}