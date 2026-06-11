#include<bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#define maxn 200010
using namespace std;
int f[maxn],cnt[maxn];
int getf(int u){
	return f[u]==u?u:f[u]=getf(f[u]);
}
void merge(int u,int v){
	int f1,f2;
	f1=getf(u),f2=getf(v);
	if(f1!=f2)f[f2]=f1;
}
int main(){
	int n,m,i,u,v,mx=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d",&u,&v),merge(u,v);
	for(i=1;i<=n;i++)cnt[getf(i)]++;
	for(i=1;i<=n;i++)mx=max(mx,cnt[i]);
	printf("%d\n",mx);	
	return 0;
}
