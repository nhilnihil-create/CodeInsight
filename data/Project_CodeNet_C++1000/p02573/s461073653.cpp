#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false),cin.tie(0);
#define ll long long
#define inf 0x3f3f3f3f
const int N=2e5+5;
//set<string>b;
//set<string>::iterator it;
int f[N],c[N];
int getfa(int u)
{
	return f[u]==u?u:f[u]=getfa(f[u]);
}
void merge(int u,int v)
{
	int f1,f2;
	f1=getfa(u);f2=getfa(v);
	if(f1!=f2) f[f2]=f1;
}
int main()
{
	IO;
	int n,m,i,u,v,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		merge(u,v);
	}
	for(i=1;i<=n;i++)
	{
		c[getfa(i)]++;
	}
	for(i=1;i<=n;i++)
	{
		ans=max(ans,c[i]);
	}
	cout<<ans<<endl;
    return 0;
}