#include<bits/stdc++.h> 
#define pa pair<int,int> 
#define MP(x,y) make_pair(x,y) 
#define fi first
#define se second 
using namespace std;
const int maxn=201;
int n,m,s,t,ans;
char c[maxn];
int a[maxn][maxn],dis[maxn][maxn];
pa q[maxn*maxn*2];
int l,r;
int dx[]={1,0};
int dy[]={0,1};
void bfs() 
{
	l=maxn*maxn+1;r=l-1;
	q[++r]=MP(1,1);
	while(l<=r) {
		pa X=q[l];l++;int x=X.fi,y=X.se;
		for(int i=0;i<2;++i) {
			int tx=dx[i]+x,ty=dy[i]+y;//cout<<tx<<" "<<ty<<"\n";
			if(tx>n) continue ;if(ty>m) continue ;if(dis[tx][ty]!=-1) continue ;
			if(a[x][y]^a[tx][ty]) {
				dis[tx][ty]=dis[x][y]+1;q[++r]=MP(tx,ty);
			}else {
				dis[tx][ty]=dis[x][y];q[--l]=MP(tx,ty);
			}
		}
	}
}

int main() 
{
	memset(dis,-1,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%s",c+1);
		for(int j=1;j<=m;++j) {
			if(c[j]=='.') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	dis[1][1]=0;
	if(a[1][1]==0) dis[1][1]++;bfs();
	if(a[n][m]==0) dis[n][m]++;
	cout<<dis[n][m]/2<<"\n";
	return 0;
}