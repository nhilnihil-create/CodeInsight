#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int w,h,a[50][50];
bool dfs(int x,int y){
	a[x][y]=0;
	for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++){
		int nx=x+dx,ny=y+dy;
		if(0<=nx && nx<h && 0<=ny && ny<w && a[nx][ny]==1) dfs(nx,ny);
	}
}
int main(){
	while(true){
		scanf("%d%d",&w,&h);
		if(w==0) break;
		int ans=0;
		rep(i,h) rep(j,w) scanf("%d",&a[i][j]);
		rep(i,h) rep(j,w) if(a[i][j]) { dfs(i,j); ans++; }
		printf("%d\n",ans);
	}
}