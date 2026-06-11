#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N * 3);
	for (auto i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v + N);
		G[u + N].push_back(v + 2 * N);
		G[u + 2 * N].push_back(v);
	}
	int S, T;
	cin >> S >> T;
	--S;
	--T;

	queue<pair<int, int>> q;
	q.push(make_pair(S, 0));
	vector<int> dp(N * 3, -1);
	dp[S] = 0;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		for (auto v : G[p.first])
		{
			if (dp[v] >= 0)
			{
				continue;
			}

			dp[v] = p.second + 1;
			q.push(make_pair(v, p.second + 1));
		}
	}

	if (dp[T] >= 0)
	{
		dp[T] /= 3;
	}
	cout << dp[T] << endl;

	return 0;
}