#include<bits/stdc++.h>
using namespace std;
const int N=10,S=50;
int n,m,s;
int a[S+1],b[S+1],c[S+1],d[S+1];
int lis[N+1];
int ans;
void dfs(int x=1,int now=1){
	if(x==n+1){
		int res=0;
		for(int i=1;i<=s;i++)if(lis[b[i]]-lis[a[i]]==c[i])res+=d[i];
		ans=max(ans,res);
		return;
	}
	lis[x]=now;
	for(int i=now;i<=m;i++)dfs(x+1,i);
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=s;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
	dfs();
	cout<<ans;
	return 0;
}