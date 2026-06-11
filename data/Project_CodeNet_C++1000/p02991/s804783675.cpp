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

int n, m, st, ed;
int h[N], e[M], ne[M], idx;
int q[N], d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int st, int ed)
{
	memset(d, -1, sizeof d);
	int hh = 0, tt = -1;
	d[st * 3] = 0;
	q[ ++ tt] = st * 3;
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] != -1) continue;
			
			d[j] = d[t] + 1;
			q[ ++ tt] = j;
			
			if (j == ed * 3) break;
		}
	}
	
	int t = d[ed * 3];
	if (t % 3) return -1;
	else return t / 3;
}

int main()
{
	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		add(a * 3, b * 3 + 1);
		add(a * 3 + 1, b * 3 + 2);
		add(a * 3 + 2, b * 3);
	}
	
	scanf("%d%d", &st, &ed);
	cout << bfs(st, ed) << endl;
	return 0;
}