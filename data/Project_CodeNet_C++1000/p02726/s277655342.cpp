#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dist[2005][2005];
int cnt[2005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, x, y;

	cin >> n >> x >> y;


	for (int i = 1; i <= n; i++)
	{
		fill(dist[i], dist[i] + 2005, 1e9);
		priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
		dist[i][i] = 0;
		que.push(make_pair(0,i));

		while (!que.empty())
		{
			int now = que.top().second;
			que.pop();

			if (now + 1 <= n)
			{
				if (dist[i][now + 1] > dist[i][now] + 1)
				{
					dist[i][now + 1] = dist[i][now] + 1;
					que.push(make_pair(dist[i][now+1],now+1));
				}
			}
			if (now == x)
			{
				if (dist[i][y] > dist[i][now] + 1)
				{
					dist[i][y] = dist[i][now] + 1;
					que.push(make_pair(dist[i][y], y));
				}
			}
			if (now - 1 > 0)
			{
				if (dist[i][now - 1] > dist[i][now] + 1)
				{
					dist[i][now - 1] = dist[i][now] + 1;
					que.push(make_pair(dist[i][now - 1], now - 1));
				}
			}
			if (now == y)
			{
				if (dist[i][x] > dist[i][now] + 1)
				{
					dist[i][x] = dist[i][now] + 1;
					que.push(make_pair(dist[i][x], x));
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cnt[dist[i][j]]++;
		}
	}

	for (int i = 1; i < n; i++)
	{
		cout << cnt[i] << '\n';
	}

	return 0;
}