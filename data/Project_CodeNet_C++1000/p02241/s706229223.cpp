//By Vlgd
#include<bits/stdc++.h>
#define INF 20000000
using namespace std;
const int N=100;
int G[N][N],n;
int vis[N]={0},dis[N]={0};
void solve(){
	int ans=0;
	for(int i=0;i<n;i++) dis[i]=INF;
	dis[0]=0;
	while(1){
		int mv=INF,u=-1;
		for(int i=0;i<n;i++){
			if(mv>dis[i]&&!vis[i]){
				mv=dis[i];
				u=i;
			}
		}
		if(u==-1) break;
		vis[u]=1;
		ans+=dis[u];

		for(int v=0;v<n;v++){
			if(!vis[v]&&G[u][v]!=-1){
				if (dis[v]>G[u][v])	dis[v]=G[u][v];
			}
		}
	}
	printf("%d\n",ans);	
}
main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&G[i][j]);
	solve();
}
