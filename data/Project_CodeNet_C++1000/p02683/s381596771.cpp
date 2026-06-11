#include <bits/stdc++.h>
using namespace std;
int a[50][50],c[50],sum[50],ans=INT_MAX,cost;
int n,m,x;
void dfs(int cur){
	if(cur==n+1){
		bool f=0;
		for(int i=1;i<=m;++i){
			if(sum[i]<x)f=1;
		}
		if(f) return ;
		ans=min(ans,cost);
		return ;
	}
	dfs(cur+1);
	for(int i=1;i<=m;++i){
		sum[i]+=a[cur][i];
	}
	cost+=c[cur];
	dfs(cur+1);
	for(int i=1;i<=m;++i)sum[i]-=a[cur][i];
	cost-=c[cur];
}
int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	dfs(1);
	if(ans==INT_MAX)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
