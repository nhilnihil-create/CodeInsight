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
	int n; cin >> n;
	vector<queue<int>> q(n + 1, queue<int>());
	for (int i = 1; i <= n; ++i)
	{
		rep(j, n - 1)
		{
			int a; cin >> a;
			q[i].push(a);
		}
	}
	queue<int> can;
	for (int i = 1; i <= n; ++i)can.push(i);
	int cnt = 0;
	bool gameExist = true;
	while (gameExist)
	{
		gameExist = false;
		vector<bool> played(n + 1);
		int i = can.size();
		while (i--)
		{
			int a = can.front();
			can.pop();
			if (q[a].empty())continue;
			if (played[a])continue;
			int b = q[a].front();
			if (played[b])continue;
			if (q[b].front() == a)
			{
				q[a].pop();
				q[b].pop();
				can.push(a);
				can.push(b);
				played[a] = true;
				played[b] = true;
				gameExist = true;
			}
		}
		++cnt;
	}
	bool finished = true;
	for (int i = 1; i <= n; ++i)if (!q[i].empty())finished = false;
	if (finished)cout << cnt - 1 << endl;
	else cout << -1 << endl;
}
