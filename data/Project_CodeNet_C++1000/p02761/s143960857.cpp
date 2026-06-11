#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> ans(n, -1);
	bool f = true;
	for (int i = 0; i < m; ++i)
	{
		int s, c;
		cin >> s >> c;
		--s;
		if (ans[s] == -1)
			ans[s] = c;
		else if (ans[s] != c)
			f = false;
	}
	if (!f)
		cout << -1 << endl;
	else if (n == 2 && ans[0] == 0)
		cout << -1 << endl;
	else if (n == 3 && ans[0] == 0)
		cout << -1 << endl;
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (ans[i] == -1 && i == 0)
				n == 1 ? ans[i] = 0 : ans[i] = 1;
			else if (ans[i] == -1)
				ans[i] = 0;
			cout << ans[i];
		}
		cout << endl;
	}
}

