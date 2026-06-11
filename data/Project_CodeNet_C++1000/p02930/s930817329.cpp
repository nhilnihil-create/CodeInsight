#include<bits/stdc++.h>
using namespace std;
int G[500+5][500+5];
void dfs(int l,int r,int s){
	if(l==r){
		return ;
	}
	int m=l+r>>1;
	for(int i=l;i<=m;++i){
		for(int j=m+1;j<=r;++j){
			G[i][j]=s;
		}
	}
	dfs(l,m,s+1);
	dfs(m+1,r,s+1);
}
int main(){
	int n;
	cin>>n;
	dfs(1,n,1);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cout<<G[i][j]<<" ";
		}
		cout<<"\n";
	}
}