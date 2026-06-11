#include<cstdio>
#include<iostream>
#include<cstring>
#define RI register int
#define CI const int&
using namespace std;
const int N=105;
int n,m,f[N][N][2]; char a[N][N];
int main()
{
	RI i,j; for (scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",a[i]+1);
	memset(f,127,sizeof(f)); if (a[1][1]=='.') f[1][1][0]=0; else f[1][1][1]=1;
	for (i=1;i<=n;++i) for (j=1;j<=m;++j) if (i!=1||j!=1)
	if (a[i][j]=='.') f[i][j][0]=min(min(f[i-1][j][0],f[i-1][j][1]),min(f[i][j-1][0],f[i][j-1][1]));
	else f[i][j][1]=min(min(f[i-1][j][0]+1,f[i-1][j][1]),min(f[i][j-1][0]+1,f[i][j-1][1]));
	return printf("%d",a[n][m]=='.'?f[n][m][0]:f[n][m][1]),0;
}