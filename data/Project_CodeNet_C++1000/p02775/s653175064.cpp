#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
int mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};

string s;
int dp[2000001][2];
bool visited[2000000][2];

int dfs(int n, bool m)
{
	if (n == (int)s.length())
		return 0;
	if (visited[n][m])
		return dp[n][m];
	visited[n][m] = 1;
	int t = s[n] - '0';
	if (m == 0)
	{
		return dp[n][m] = min(dfs(n + 1, 0) + t, dfs(n + 1, 1) + t + 1);
	}
	else
	{
		if (n == (int)s.length() - 1)
			t = 10 - t;
		else
			t = 9 - t;
		return dp[n][m] = min(dfs(n + 1, 0) + t + 1, dfs(n + 1, 1) + t);
	}
}

int main()
{
	cin >> s;
	s = "0" + s;
	cout << dfs(0, 0);
}