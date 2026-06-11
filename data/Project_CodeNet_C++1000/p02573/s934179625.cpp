#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m;
int fa[N],sum[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		int fx=find(x),fy=find(y);
		fa[fx]=fy;
	}
	for(int i=1;i<=n;i++){
		int fi=find(i);
		sum[fi]++;
	}
	sort(sum+1,sum+1+n);
	cout<<sum[n];
	return 0;
}