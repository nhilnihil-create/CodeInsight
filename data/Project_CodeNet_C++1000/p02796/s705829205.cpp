#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

int dp[100001];
map <long long int, int> memo;
set <long long int,greater<long long int>> s;
vector <long long int> v2[100001];
bool cmp(pair <long long int, long long int> a, pair <long long int, long long int> b)
{
	if (a.first - a.second == b.first - b.second)
	{
		return a.first + a.second < b.first + b.second;
	}
	return a.first - a.second < b.first - b.second;
}
bool cmp2(pair <long long int, long long int> a, pair <long long int, long long int> b)
{
	if (a.second==b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	vector<pair<long long int, long long int>> v;
	long long int a, b;
	//ifstream cin("10.txt");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		s.insert(v[i].first + v[i].second);
		//cout << v[i].first - v[i].second << ' ' << v[i].first + v[i].second << '\n';
	}
	
	int m = s.size();

	for (auto it : s)
	{
		memo[it] = m--;
	}

	int Max = 0;
	int res = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		auto it = s.lower_bound(v[i].first - v[i].second);
		if (it == s.end())
		{
			int idx = memo[v[i].first + v[i].second];
			v2[0].push_back(idx);
		}
		else
		{
			int idx1 = memo[*it];
			int idx2 = memo[v[i].first + v[i].second];
			v2[idx1].push_back(idx2);
		}
	}

	for (int i = 0; i <= s.size(); i++)
	{
		Max = max(Max, dp[i]);
		for (int j = 0; j < v2[i].size(); j++)
		{
			//cout << i << ' ' << v2[i][j] << '\n';
			dp[v2[i][j]] = max(dp[v2[i][j]], Max + 1);
			res = max(res, dp[v2[i][j]]);
		}
	}

	cout << res << '\n';

	return 0;
}