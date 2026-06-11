#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 300010, M = 3 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], q[M];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int st, int ed)
{
	memset(dist, -1, sizeof dist);
	int hh = 0, tt = -1;
	dist[st * 3] = 0;
	q[ ++ tt] = st * 3;
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] != -1) continue;
			
			dist[j] = dist[t] + 1;
			q[ ++ tt] = j;
		}
	}
	
	if (dist[ed * 3] == -1) return -1;
	else return dist[ed * 3] / 3;
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
	printf("%d\n", bfs(st, ed));
    return 0;
}