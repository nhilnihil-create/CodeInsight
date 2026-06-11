#include <bits/stdc++.h>
using namespace std;
const int maxn=123;
int m,n,x,c[maxn],a[maxn][maxn],sum[maxn],mini=INT_MAX,cost;
void dfs(int cur){
	if(cur==n+1){
		bool bad=0;
		for(int i=0;i<m;i++)
			if(sum[i]<x)bad=1;
		if(bad==0){
			mini=min(mini,cost);
		}
		return;
	}
	for(int i=0;i<m;i++)sum[i]+=a[cur][i];
	cost+=c[cur];
	dfs(cur+1);//选 
	for(int i=0;i<m;i++)sum[i]-=a[cur][i];
	cost-=c[cur];
	dfs(cur+1);//不选 
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	}
	dfs(0);
	if(mini==INT_MAX)printf("%d",-1);
	else printf("%d",mini);
	return 0;
}