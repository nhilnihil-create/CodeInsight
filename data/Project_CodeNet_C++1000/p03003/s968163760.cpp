#include <bits/stdc++.h>
using namespace std;

const int M=2005;
const int MO=1e9+7;
inline void addv(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline void subv(int &x,int y)
{
	x-=y;
	if(x<0) x+=MO;
}
inline int sub(int x,int y)
{
	x-=y;
	if(x<0) x+=MO;
	return x;
}
inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}

int s[M],t[M];

int all[M][M]; 
int dp[M][M]; // select i,j 

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&t[i]);
	for(int i=0;i<=n;i++)
		all[i][0]=1;
	for(int i=0;i<=m;i++)
		all[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i]!=t[j]) dp[i][j]=0;
			else dp[i][j]=all[i-1][j-1];
			all[i][j]=add(all[i][j-1],all[i-1][j]);
			subv(all[i][j],all[i-1][j-1]);
			addv(all[i][j],dp[i][j]);
		}
	printf("%d\n",all[n][m]);
	return 0;
}