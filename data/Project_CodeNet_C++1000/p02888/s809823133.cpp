#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(2e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int L[2005];
int main ()
{
	int n = qread();
	for ( int i = 1 ; i <= n ; i++ )
		cin >> L[i];
	sort ( L+1 , L+1+n );
	int cnt = 0;
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = i+1 ; j <= n ; j++ )
		{
			int d = L[i] + L[j];
			int tot = lower_bound( L+1 , L+n+1 , d ) - L -1 ;
			cnt += tot-j;
			if ( d == L[tot] )	cnt--;
		}
	}
	cout << cnt << endl;
}