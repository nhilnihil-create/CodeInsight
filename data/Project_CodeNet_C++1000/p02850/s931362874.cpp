#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 2 * N;

int n, k;
int h[N], e[M], ne[M], idx;
int d[N];
int color[M];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa, int c)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == fa) continue;
		
		if ( ++ c > k) c = 1;
		color[i] = c;
		dfs(j, u, c);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
		d[a] ++ , d[b] ++ ;
		k = max(k, max(d[a], d[b]));
	}

	dfs(1, -1, 0);

	printf("%d\n", k);
	for (int i = 0; i < idx - 1; i += 2)
		printf("%d\n", max(color[i], color[i + 1]));
	
	return 0;
}