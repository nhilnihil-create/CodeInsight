#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int f[N+10];
int sz[N+10];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int merge(int u,int v){
	int uf=find(u);
	int vf=find(v);
	if(uf!=vf){
		sz[uf]+=sz[vf];
		sz[vf]=0;
		f[vf]=uf;
	}
	return sz[uf];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	int ans=1;
	while(m--){
		int a,b;
		cin>>a>>b;
		ans=max(ans,merge(a,b));
	}
	cout<<ans;
}