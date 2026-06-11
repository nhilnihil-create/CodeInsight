#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 2 * N, mod = 1e9 + 7;

int n, m;
int h[N], e[M], ne[M], idx;
int fact[N], infact[N];
vector<int> depth[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

void init()
{
	memset(h, -1, sizeof h);
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++ )
	{
		fact[i] = (LL)fact[i - 1] * i % mod;
		infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
	}
}

void dfs(int u, int fa, int d)
{
	int cnt = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (fa == j) continue;
		
		cnt ++ ;
		dfs(j, u, d + 1);
	}
	depth[d + 1].PB(cnt);
}

int main()
{
	scanf("%d%d", &n, &m);
	init();
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	
	dfs(1, -1, 1);
	
	int res = m;
	for (int i = 2; i <= n; i ++ )
		for (auto u : depth[i])
			if (i == 2) res = (LL)res * fact[m - 1] % mod * infact[m - 1 - u] % mod;
			else res = (LL)res * fact[m - 2] % mod * infact[m - 2 - u] % mod;
	printf("%d\n", res);
    return 0;
}