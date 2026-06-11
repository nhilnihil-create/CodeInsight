#include<bits/stdc++.h>
using namespace std;
int n,m,q,mx,cnt;
int al[15];
struct strukt
{
	int a;
	int b;
	int c;
	int d;
}k[55];
void dfs(int s)
{
	if(s>n)
	{
		int cn=0;
		for(int i=1;i<=q;i++)
			if(al[k[i].b]-al[k[i].a]==k[i].c)
				cn+=k[i].d;
		mx=max(mx,cn);
	}
	else
		for(int i=(s==1?1:al[s-1]);i<=m;i++)
		{
			al[s]=i;
			dfs(s+1);
		}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++)
		cin>>k[i].a>>k[i].b>>k[i].c>>k[i].d;
	dfs(1);
	cout<<mx;

	return 0;
}