#include<iostream>
using namespace std;
int fa[200001],s[200001];
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		s[find(i)]++;
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
		maxn=max(s[i],maxn);
	cout<<maxn<<endl;	
	return 0;		
}