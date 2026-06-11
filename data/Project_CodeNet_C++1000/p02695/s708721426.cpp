#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N], b[N], c[N], n, m ,q, ans, tmp[12], d[N];
int check()
{
	int res = 0;
	for (int i = 1; i <= q; i++)
		if (tmp[b[i]] - tmp[a[i]] == c[i])
			res += d[i];
	return res;
}
void dfs(int maxx, int x)
{
	if (x > n)
	{
		ans = max(ans, check());
		return;
	}
	for (int i = maxx; i <= m; i++)
	{
		tmp[x] = i;
		dfs(i, x + 1);
	}
}
int main() 
{
	cin>>n>>m>>q;
	for (int i = 1; i <= q; i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	dfs(1, 1);
	cout<<ans;
    return 0;
}
