#include <bits/stdc++.h>
using namespace std;
int n,m,x,c[50],a[50][50],b[50],d[50],l,sum=INT_MAX,cost;
void dfs(int s){
	int i,j,k;
	if(s==l+1){
		for(k=1;k<=m;k++)d[k]=0;
		for(j=1;j<=l;j++)
			for(k=1;k<=m;k++)d[k]+=a[b[j]][k];
		for(k=1;k<=m;k++)
			if(d[k]<x)return;
		cost=0;
		for(j=1;j<=l;j++)cost+=c[b[j]];
		sum=min(sum,cost);
		return ;
	}
	for(i=b[s-1]+1;i<=n;i++){
		b[s]=i;
		dfs(s+1);
	}
}
int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(l=1;l<=n;l++)b[0]=0,dfs(1);
	if(sum==INT_MAX)cout<<-1<<endl;
	else cout<<sum<<endl;
	return 0;
}