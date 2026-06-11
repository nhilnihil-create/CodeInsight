#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

int     main()
{
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> c(n, 0);
	for (int i = 1; i < n; i++) {
		vector<int> dp(n+1, INF);
		queue<int> q;
		q.push(i);
		dp[i] = 0;
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			if (f-1 >= 1 && dp[f-1] == INF)
			{
				dp[f-1] = dp[f]+1;
				q.push(f-1);
				if (f-1 > i)
					c[dp[f-1]]++;
			}
			if (f+1 <= n && dp[f+1] == INF)
			{
				dp[f+1] = dp[f]+1;
				q.push(f+1);
				if (f+1 > i)
					c[dp[f+1]]++;
			}
			if (f == x && dp[y] == INF)
			{
				dp[y] = dp[f]+1;
				q.push(y);
				if (y > i)
					c[dp[y]]++;
			}
			if (f == y && dp[x] == INF)
			{
				dp[x] = dp[f]+1;
				q.push(x);
				if (x > i)
					c[dp[x]]++;
			}

		}
	}
	for(int i = 1; i <= n-1; i++)
	{
		cout << c[i] << endl;
	}
}
