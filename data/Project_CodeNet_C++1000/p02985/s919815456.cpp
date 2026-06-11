#include<iostream>
#include<set>
#include<string.h>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct edge{
	int to, next;
}e[200005];
int head[100005], tot, n, k, x, y, mod = 1000000007;
ll ans;
void add(int u, int v)
{
	e[tot].to = v, e[tot].next = head[u],  head[u] = tot++;
}
void dfs(int x, int fa, int dep)
{
	int num = 0;
	for (int u = head[x]; ~u; u = e[u].next)
	{
		int v = e[u].to;
		if (v == fa)	continue;
		dfs(v, x, dep + 1);
		
		if (dep == 0)
		{
			ans = ans * (k - num - 1) % mod;
			if (k - num - 1 <= 0)	ans = 0;
		}
		else
		{
			ans = ans * (k - num - 2) % mod;
			if (k - num - 2 <= 0)	ans = 0;
		}	
		num++;
	}
}
signed main(){
	while (~scanf("%d%d", &n, &k))
	{
		ans = k;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs(1, -1, 0);
		printf("%lld\n", ans);
	}
}
