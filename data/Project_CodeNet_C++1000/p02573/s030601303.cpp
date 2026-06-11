#include<bits/stdc++.h>

using namespace std;

int f[200010],sz[200010];

int zzs(int u)
{
	return f[u]==u?u:f[u]=zzs(f[u]);
}
void sq(int u,int v)
{
	int a,b;
	a=zzs(u);
	b=zzs(v);
	if(a!=b)
		f[b]=a;
}
int main()
{
	int n,m,u,v,sn=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		sq(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		sz[zzs(i)]++;
	}
	for(int i=1;i<=n;i++)
	{
		sn=max(sn,sz[i]);
	}
	printf("%d\n",sn);	
	return 0;
}