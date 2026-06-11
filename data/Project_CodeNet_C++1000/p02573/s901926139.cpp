#include<cstdio>
#include<iostream>
using namespace std;
const int N=2e5+5;
int n,m,x,y,xx,yy,mx,f[N],s[N];
int get(int x)
{
	if (f[x]==x) return x;
	return f[x]=get(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		xx=get(x),yy=get(y);
		if (xx!=yy)
		{
			if (s[xx]<s[yy]) f[xx]=yy,s[yy]+=s[xx]; else f[yy]=xx,s[xx]+=s[yy];
		}
	}
	for (int i=1;i<=n;i++) if (get(i)==i) mx=max(mx,s[i]);
	printf("%d",mx); 
	return 0;
}