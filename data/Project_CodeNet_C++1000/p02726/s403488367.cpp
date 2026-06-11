#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, x, y, a[2020], d[2020];
vector<int> g[2020];

void bfs(int s)
{
	for (int i = 1; i <= n; i++) d[i] = -1;
	queue<int> q; q.push(s); d[s] = 0;
	while (!q.empty()){
		int x = q.front(); q.pop();
		for (auto &y : g[x]) if (d[y] == -1){
			q.push(y); d[y] = d[x] + 1;
		}
	}
	for (int i = s + 1; i <= n; i++) a[d[i]]++;
}

int main()
{
	scanf ("%d %d %d", &n, &x, &y);
	g[x].push_back(y);
	g[y].push_back(x);
	for (int i = 2; i <= n; i++){
		g[i].push_back(i - 1);
		g[i - 1].push_back(i);
	}
	for (int i = 1; i <= n; i++) bfs(i);

	for (int i = 1; i < n; i++) printf ("%d\n", a[i]);
	return 0;
}