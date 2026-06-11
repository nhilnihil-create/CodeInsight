#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}
int main ()
{
	LL s;
	scanf ( "%lld",&s );
	int a , b , c , d;
	a = d = (int)sqrt(s);
	b = c = 0;
	while ( s > 1ll * a * d ){
		if ( a < d ) a++;
		else d++;
	}
	LL k = 1ll * a * d - s;
	for ( int i = 1 ; i <= sqrt(k) ; i++ )
	{
		if ( k % i == 0 )
		{
			if ( i <= 1e9 && k / i <= 1e9 ){
				b = i;
				c = k / i;
				break;
			}
		}
	}
	printf ( "0 0 %d %d %d %d\n",a,b,c,d );
	return 0;
}