#include<cstdio>
typedef long long ll;
struct edge
{
	int e, nxt;
};
edge a[200200]; int m;
int sp[100100];
int n; ll K;
const ll base = 1'000'000'007;
ll d[100100];
int par[100100];
bool v[100100];
int deg[100100];
int q[100100], hd = 1, tl = 2;
ll cmod[100100];
int main()
{
	scanf("%d%lld", &n, &K);
	cmod[0] = 1;
	for (int i = 1; i <= K-1; i++)
		cmod[i] = (cmod[i - 1] * (K - 1 - i)) % base;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[++m].e = v; a[m].nxt = sp[u]; sp[u] = m;
		a[++m].e = u; a[m].nxt = sp[v]; sp[v] = m;
	}
	q[1] = 1; v[1] = true;
	while (hd < tl)
	{
		int cur = q[hd++];
		d[cur] = 1;
		for (int j = sp[cur]; j; j = a[j].nxt)
		{
			if (v[a[j].e]) continue;
			v[a[j].e] = true;
			q[tl++] = a[j].e; par[a[j].e] = cur; deg[cur]++;
		}
	}
	for (int i = n; i > 1; i--)
	{
		int cur = q[i];
		d[cur] = (d[cur] * cmod[deg[cur]]) % base;
		d[par[cur]] = (d[par[cur]] * d[cur]) % base;
	}
	for (int i = 0; i <= deg[1]; i++) d[1] = (d[1] * (K - i)) % base;
	printf("%lld\n", d[1]);
	return 0;
}
