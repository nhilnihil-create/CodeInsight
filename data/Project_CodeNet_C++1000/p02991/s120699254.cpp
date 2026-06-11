#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 300010, M = 2 * N;

int n, m;
int h[N], ne[M], e[M], idx;
int q[M], d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int st, int ed)
{
	int hh = 0, tt = -1;
	q[ ++ tt] = st;
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j]) continue;
			
			q[ ++ tt] = j;
			d[j] = d[t] + 1;
		}
	}
	
	if (d[ed]) return d[ed] / 3;
	else return -1;
}

int main()
{
	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(3 * a, 3 * b + 1);
		add(3 * a + 1, 3 * b + 2);
		add(3 * a + 2, 3 * b);
	}
	
	int st, ed;
	scanf("%d%d", &st, &ed);
	printf("%d\n", bfs(3 * st, 3 * ed));
	return 0;
}