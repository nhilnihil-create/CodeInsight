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
	string s;
	cin >> s;
	int len = s.size();
	vector<int> ans(len, 0);
	Pair c(1, 0);
	for (int i = 1; i < len; i++) {
		if (s[i] == 'R')
		{
			if (i & 1)
				c.second++;
			else
				c.first++;
			continue ;
		}
		if (i & 1)
		{
			ans[i] += c.second;
			ans[i-1] += c.first;
		}
		else
		{
			ans[i] += c.first;
			ans[i-1] += c.second;
		}
		while (i < len && s[i] == 'L')
			i++;
		if (i & 1)
			c = make_pair(0, 1);
		else
			c = make_pair(1, 0);
	}
	if ((len - 1) & 1)
		c = make_pair(0, 1);
	else
		c = make_pair(1, 0);
	for (int i = len - 2; i >= 0; i--) {
		if (s[i] == 'L')
		{
			if (i & 1)
				c.second++;
			else
				c.first++;
			continue ;
		}
		if (i & 1)
		{
			ans[i] += c.second;
			ans[i+1] += c.first;
		}
		else
		{
			ans[i] += c.first;
			ans[i+1] += c.second;
		}
		while (i >= 0 && s[i] == 'R')
			i--;
		if (i & 1)
			c = make_pair(0, 1);
		else
			c = make_pair(1, 0);
	}
	cout << ans[0];
	for (int i = 1; i < len; i++)
		cout << SEP << ans[i];
	cout << endl;
}
