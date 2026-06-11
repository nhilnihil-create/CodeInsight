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
	int N, K;
	cin >> N >> K;
	vector<vector<int>> G(N);
	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<int> q;
	q.push(0);
	ll result = K;
	ll mod = (ll)1e9 + 7;
	vector<bool> used(N);
	used[0] = true;
	while (!q.empty())
	{
		auto u = q.front();
		q.pop();
		auto count = 0;
		for (auto v : G[u])
		{
			if (used[v])
			{
				continue;
			}

			used[v] = true;
			q.push(v);
			if (u == 0)
			{
				result = result * (K - count - 1) % mod;
			}
			else
			{
				result = result * (K - count - 2) % mod;
			}
			++count;
		}
	}

	cout << result << endl;

	return 0;
}