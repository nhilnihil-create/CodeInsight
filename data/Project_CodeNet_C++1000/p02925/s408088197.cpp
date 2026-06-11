#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 1000010;

int n, m;
int g[N][N];
int h[M], e[M], ne[M], idx;
int q[M], d[M], f[M];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int top_sort(int st)
{
	int hh = 0, tt = -1;
	q[ ++ tt] = st;
	f[st] = 0;
			
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			
			if ( -- d[j] == 0)
			{
				f[j] = f[t] + 1;
				q[ ++ tt] = j;
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= m; i ++ )
		if (!f[i]) return -1;
		else res = max(res, f[i]);
	return res;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		for (int j = i + 1; j <= n; j ++ )
			g[i][j] = g[j][i] = ++ m;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 0, a = m + 1; j < n - 1; j ++ )
		{
			int t;
			scanf("%d", &t);
			int b = g[i][t];
			add(a, b);
			d[b] ++ ;
			a = b;
		}
		
	cout << top_sort(m + 1) << endl;
    return 0;
}