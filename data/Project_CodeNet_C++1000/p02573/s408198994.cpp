#include<bits/stdc++.h>
using namespace std;
int fa[200005],num[200005];
int find(int x){
	if(x==fa[x])
	    return fa[x];
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[y]=x;
		num[x]+=num[y];
	}
}
int main(){
	int n,m,x,y,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		fa[i]=i;
		num[i]=1;
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		add(x,y);
	}
	for(int i=0;i<n;i++){
		ans=max(ans,num[i]);
	}
	cout<<ans;
	return 0;
}