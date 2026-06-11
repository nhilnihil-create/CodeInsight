#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int fa[N],siz[N];
inline int find(int x)
{
	if(x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}
inline void merge(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx == fy) return ;
	else if(siz[fx] < siz[fy]) fa[fx] = fy,siz[fy] += siz[fx];
	else fa[fy] = fx,siz[fx] += siz[fy];
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		fa[i] = i, siz[i] = 1;
	for(int i=1; i<=m; i++)
	{
		int x,y;
		cin >> x >> y;
		merge(x,y);
	}
	int ans = 0;
	for(int i=1; i<=n; i++)
		ans = max(ans, siz[i]);
	cout << ans << '\n';
}