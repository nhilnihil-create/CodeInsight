#include<iostream>
#include<algorithm>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <new>
#include <cmath>
#include<fstream>
using namespace std;
const long long MAXN = 200, mod = 1000000007, inff = 1000000007;
long long n, m, x1, yy, x2, y2, x, y , d, z , mini, dist[MAXN], di[MAXN][MAXN], edg[MAXN][MAXN], inf = 1000000000000000000;
pair <long long, pair<long long, long long> > edge[100000];
bool is[MAXN][MAXN];
bool iscycle()
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = inf;
	}
	dist[0] = 0;
	long long mmm = m + n + 1;
	while (mmm--)
	{
		for (int i = 0; i < m; i++)
		{
			x = edge[i].second.first;
			y = edge[i].second.second;
			d = edge[i].first;
			if (dist[x] != inf)
			dist[y] = min(dist[y], dist[x] + d);
		}
	}
	for (int i = 0; i < m; i++)
	{
		x = edge[i].second.first;
		y = edge[i].second.second;
		d = edge[i].first;
		if (dist[x] != inf && dist[y] > dist[x] + d)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> d;
		edg[x][y] = d;
		edge[i].first = d;
		edge[i].second.first = x;
		edge[i].second.second = y;
		is[x][y] = true;
	}
	if (iscycle())
	{
		cout << "NEGATIVE CYCLE" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) di[i][j] = 0;
				else if (is[i][j]) di[i][j] = edg[i][j];
				else di[i][j] = inf;
			}
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (di[i][k] != inf && di[k][j] != inf)
					di[i][j] = min(di[i][j], di[i][k] + di[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (di[i][j] == inf) cout << "INF";
				else cout << di[i][j];
				if (j != n-1)cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
