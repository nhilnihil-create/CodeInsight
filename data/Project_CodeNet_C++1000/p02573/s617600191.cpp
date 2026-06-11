#include<iostream>
#include<cstdio>
using namespace std;
int n,m,f[300006],a,b,ans=1,max1[300006],s;
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
void merge(int i,int j)
{
	s=find(i);
	f[find(i)]=find(j);
	max1[f[j]]+=max1[s];
	if(ans<max1[f[j]])
	ans=max1[f[j]];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		f[i]=i;max1[i]+=1;
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		if(find(a)!=find(b))
		merge(a,b);
	}
	printf("%d",ans);
	return 0;
}