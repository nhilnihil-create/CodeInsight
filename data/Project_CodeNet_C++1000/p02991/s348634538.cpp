#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> e(n);
	rep(i, m)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		e[u].push_back(v);
	}
	int s, t; cin >> s >> t;
	--s, --t;
	vector<vector<int>> dp(n, vector<int>(3, -1));
	queue<pair<int, int>> q;
	dp[s][2] = 0;
	q.push(make_pair(s, 2));
	while (!q.empty())
	{
		int now = q.front().first;
		int step = q.front().second;
		q.pop();
		for (int next : e[now])
		{
			int nextStep = (step + 1) % 3;
			if (dp[next][nextStep] == -1)
			{
				dp[next][nextStep] = dp[now][step];
				if (nextStep == 0)++dp[next][nextStep];
				q.push(make_pair(next, nextStep));
			}
		}
	}
	cout << dp[t][2] << endl;
}
