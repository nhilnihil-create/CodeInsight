#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 438705
using namespace std;
int f[p],siz[p];
inline int findx(int x);
inline void unions(int x,int y);
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(fint i=1;i<=n;i++)
	f[i]=i,siz[i]=1;
	int x,y;
	for(fint i=1;i<=m;i++)
	cin>>x>>y,unions(x,y);
	int ans=0;
	for(fint i=1;i<=n;i++)
	ans=max(siz[i],ans);
	cout<<ans;
	return 0;
}

inline int findx(int x)
{
	if(f[x]==x)
	return x;
	return f[x]=findx(f[x]);
}

inline void unions(int x,int y)
{
	int fx=findx(x),fy=findx(y);
	if(fx!=fy)
	f[fx]=fy,siz[fy]+=siz[fx];
	return ;
}