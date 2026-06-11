#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int fr[200010],s[200010]={1};
int find(int x)
{
	if(fr[x]==x) return x;
	else return fr[x]=find(fr[x]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
	fr[i]=i;s[i]=1;}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int kx=find(x),ky=find(y);
		if(kx!=ky){
			fr[ky]=kx;
			s[kx]+=s[ky];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(fr[i]==i)
		  ans=max(ans,s[i]);
	}
	printf("%d\n",ans);
}