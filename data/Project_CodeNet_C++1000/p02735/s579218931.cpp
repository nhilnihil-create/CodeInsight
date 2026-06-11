#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[105][105],n,m;
char s[105][105];
int main()
{int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	memset(f,127/2,sizeof(f));
	f[1][1]=(s[1][1]=='#');
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i+1<=n)
			f[i+1][j]=min(f[i+1][j],f[i][j]+(s[i][j]!=s[i+1][j]));
			if (j+1<=m)
			f[i][j+1]=min(f[i][j+1],f[i][j]+(s[i][j]!=s[i][j+1]));
		}
	}
	printf("%d",(f[n][m]+1)/2);
}