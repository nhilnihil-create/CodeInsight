#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int fa[N],num[N];
int father(int x)
{
	if(fa[x]==x)
		return fa[x];
	else
		return fa[x]=father(fa[x]);
}
void add(int x,int y)
{
	x=father(x);
	y=father(y);
	if(x!=y)
	{
		fa[y]=x;
		num[x]+=num[y];
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<N;i++)
	{
		fa[i]=i;
		num[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	int maxn=-1;
	for(int i=1;i<=N;i++)
		maxn=max(maxn,num[i]);
	cout<<maxn<<endl;
	return 0;
}