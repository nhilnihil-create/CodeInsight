#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+100;


int n,m;
int a[N],b[N];
int fa[N];
int bar[N];

int find(int x)
{
	return fa[x]  = (fa[x] == x ? x : find(fa[x]));
}


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i] = i;
	//memset(vis,false,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		int fx = find(a[i]);
		int fy = find(b[i]);
		if(fx==fy) continue;
		fa[fx] = fy;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		int nowfa = find(i);
		bar[nowfa]++;
		ans = max(ans,bar[nowfa]);
	}
	//for(int i=1;i<=m;i++)
		//scanf("%d",&b[i]);
	cout << ans << endl;
	return 0;
}