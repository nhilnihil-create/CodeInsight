#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 1 << 12;

int n, m;
int a[N], b[N], c[M];
int f[N][M];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++ )
	{
		scanf("%d%d", &a[i], &b[i]);
		for (int j = 0; j < b[i]; j ++ )
		{
			int t;
			scanf("%d", &t);
			c[i] += 1 << (t - 1);
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	
	for (int i = 1; i <= m; i ++ )
	{
		memcpy(f[i], f[i - 1], sizeof f[i]);
		for (int j = 0; j < 1 << n; j ++ )
		{
			int t = min(f[i - 1][j | c[i]], f[i - 1][j] + a[i]);
			f[i][j | c[i]] = min(f[i][j | c[i]], t);
		}
	}
	
	int res = f[m][(1 << n) - 1];
	if (res == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", res);
    return 0;
}