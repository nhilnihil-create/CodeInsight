#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int dfs(int i, vector<int>& dp, vector<vector<int>>& toid, vector<bool>& visited, vector<bool>& calculated)
{
	visited[i] = true;

	if (toid[i].empty()) {
		calculated[i] = true;
		dp[i] = 1;
		return dp[i];
	}

	for (auto& j : toid[i]) {
		if (calculated[j]) {
			dp[i] = max(dp[i], dp[j] + 1);
			continue;
		}
		if (visited[j]) {
			return -1;
		}

		int ans = dfs(j, dp, toid, visited, calculated);
		if (ans == -1) {
			return -1;
		}
		dp[i] = max(dp[i], ans + 1);
	}

	calculated[i] = true;
	return dp[i];
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> av(n, vector<int>(n-1));
	for (auto& i : av) {
		for (auto& j : i) {
			cin >> j;
			--j;
		}
	}

	vector<vector<int>> idTable(n, vector<int>(n));

	int v = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			idTable[i][j] = v++;
		}
	}

	vector<vector<int>> toid(v);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			av[i][j] = idTable[min(i, av[i][j])][max(i, av[i][j])];
		}
		for (int j = 0; j < n - 2; ++j) {
			toid[av[i][j+1]].push_back(av[i][j]);
		}
	}

	int ret = 0;
	vector<int> dp(v, -1);
	vector<bool> visited(v, false);
	vector<bool> calculated(v, false);
	for (int i = 0; i < v; ++i)
	{
		if (calculated[i]) {
			continue;
		}

		int ans = dfs(i,dp,toid, visited, calculated);
		if (ans == -1) {
			cout << -1;
			return 0;
		}
		ret = max(ret, ans);
	}

	cout << ret << endl;

	return 0;
}