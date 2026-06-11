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


int dest = 0;
void get_dest(int N){
	for ( int i = 1 ; i <= N ; i++ )
		dest |= (1<<i);
}

int N , M;
int a[1005] , b[1005] ,c[1005][15];
bool flag[15];

const int inf = 1 << 30;
int dp[1<<15];
int vis[1<<15] = {0};
int num[1<<15],cnt = 0 ;
void dfs ( int s )
{
	if ( dp[s] != inf && vis[s] == 1 )
		return;
	vis[s] = 1;
	int res = dp[s];
	for ( int i = 0 ; i < cnt ; i++ )
	{
		int x = num[i];
		int tmp = s&(~x);
		if ( tmp != s ) 
		{	
			dfs(tmp);
			dp[s] = min ( dp[s] , dp[tmp]+dp[x] ) ;
		}
	}
}
int main ()
{
	N = qread();
	M = qread();
	get_dest(N);
	for ( int i = 1 ; i <= M ; i++ )
	{
		a[i] = qread();
		b[i] = qread();
		for ( int j = 1 ; j <= b[i] ; j++ )
		{
			int x = qread();
			c[i][x] = 1;
			flag[x] = true;
		}
	}
	for ( int i = 1 ; i <= N ; i++ )
		if ( flag[i] == false )
		{
			cout << "-1" << endl;
			return 0;
		}
	

	for ( int i = 0 ; i <= dest ; i++ )	dp[i] = inf;
	dp[0] = 0;
	for ( int i = 1 ; i <= M ; i++ )
	{
		int s = 0;
		for ( int j = 1 ; j <= N ; j++ )
			if (c[i][j])
				s |= (1<<j) ;
		if ( dp[s] == inf )
			num[cnt++] = s;
		dp[s] = min ( dp[s] , dp[0]+a[i] );
	}
	dfs(dest);
	cout << dp[dest] << endl;
}