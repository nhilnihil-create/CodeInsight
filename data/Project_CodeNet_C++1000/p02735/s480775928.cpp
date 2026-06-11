#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
#define INF 1e9
using namespace std;
int n,m,f[N+5][N+5][2];char s[N+5][N+5];
int main()
{
	RI i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",s[i]+1);
	s[1][1]^'#'?(f[1][1][0]=0,f[1][1][1]=INF):(f[1][1][0]=INF,f[1][1][1]=1);
	for(i=1;i<=n;++i) f[i][0][0]=f[i][0][1]=INF;
	for(i=1;i<=m;++i) f[0][i][0]=f[0][i][1]=INF;
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(i^1||j^1)
		s[i][j]^'#'?(f[i][j][0]=min(min(f[i-1][j][0],f[i][j-1][0]),min(f[i-1][j][1],f[i][j-1][1])),f[i][j][1]=INF)
		:(f[i][j][0]=INF,f[i][j][1]=min(min(f[i-1][j][0],f[i][j-1][0])+1,min(f[i-1][j][1],f[i][j-1][1])));
	return printf("%d",min(f[n][m][0],f[n][m][1])),0;
}