#include <bits/stdc++.h>
using namespace std;
int h,w,k,a[15],ans,i,j;
char c[10][10];
bool f[15];
void check(int len)
{
	bool x[10],y[10];
	int sum=0;
	memset(x,true,sizeof x);
	memset(y,true,sizeof y);
	for (int i=1;i<=len;i++)
	if (a[i]<=h) x[a[i]]=false;else y[a[i]-h]=false;
	for (int i=1;i<=h;i++)
	 for (int j=1;j<=w;j++)
	  if (c[i][j]=='#'&&x[i]&&y[j]) sum++;
	if (sum==k) ans++;
}
void dfs(int x)
{
	check(x);
	if (x>=h+w) return;
	for (int i=1;i<=h+w;i++)
	if (!f[i]&&i>a[x])
	{
		a[x+1]=i;
		f[i]=true;
		dfs(x+1);
		f[i]=false;
	}
}
int main()
{
	scanf("%d%d%d\n",&h,&w,&k);
	for (i=1;i<=h;++i)
	{
		for (j=1;j<=w;j++)
		scanf("%c",&c[i][j]);
		scanf("\n");
	}
	dfs(0);
	printf("%d",ans);
}