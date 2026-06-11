#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,ans;
char G[N][N];
bitset<N> vis[N];
const int move[4][2]={
	{0,1},{0,-1},{1,0},{-1,0}	
};
void dfs(int x,int y,char k){
	if(x<1||x>n||y<1||y>m||G[x][y]!=k||vis[x][y])
		return;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
		dfs(x+move[i][0],y+move[i][1],k);
}
signed main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>m&&n){
		memset(G,0,sizeof(G)),ans=0;
		for(int i=1;i<=n;vis[i++].reset())
			for(int j=1;j<=m;j++)
				cin>>G[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!vis[i][j])
					dfs(i,j,G[i][j]),ans++;
		cout<<ans<<endl;
	}
}