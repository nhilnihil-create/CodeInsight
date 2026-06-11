#include <bits/stdc++.h>
using namespace std;
int n,m,K;
char s[20][20];
bool vis[20];
int ans=0;
void check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=1;j<=m;j++){
			if(vis[n+j]) continue;
			if(s[i][j]=='#') sum++;
		}
	}
	ans+=(sum==K);
}
void dfs(int x){
	if(x==n+m+1){
		check(); return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	//freopen("data.in","r",stdin);
	scanf("%d %d %d\n",&n,&m,&K);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	dfs(1);
	cout<<ans<<endl;
}