#include <bits/stdc++.h>
#define m_k make_pair
#define inf 0x3f3f3f3f
using namespace std;
const int N=110;
int n,m,dp[N][N],vi[N][N];
char mp[N][N];
void bfs()
{
	queue <pair<int,int> > q;
	q.push(m_k(2,1));
	q.push(m_k(1,2));
	vi[1][2]=vi[2][1]=1;
	while (!q.empty())
	{
		int x,y;
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if (mp[x][y]=='.') dp[x][y]=min(dp[x-1][y],dp[x][y-1]);
		if (mp[x][y]=='#')
		{
			int a,b;
			a=dp[x-1][y];b=dp[x][y-1];
			if (mp[x-1][y]!='#') a++;
			if (mp[x][y-1]!='#') b++;
			dp[x][y]=min(a,b);
		}
		int dx,dy;
		dx=x+1;dy=y;
		if (dx<=n && !vi[dx][dy])
		{
			q.push(m_k(dx,dy));
			vi[dx][dy]=1;
		}
		dx=x;dy=y+1;
		if (dy<=m && !vi[dx][dy])
		{
			q.push(m_k(dx,dy));
			vi[dx][dy]=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	  scanf("%s",mp[i]+1);
	memset(dp,0x3f,sizeof(dp));
	if (mp[1][1]=='#') dp[1][1]=1;
	else dp[1][1]=0;
	bfs();
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=m;j++)
//		  printf("%d ",dp[i][j]);
//		printf("\n");
//	}
	printf("%d\n",dp[n][m]);
}