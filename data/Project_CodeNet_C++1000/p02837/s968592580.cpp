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
	int n;
	cin >> n;
	vector<map<int, int>> g(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int x, y;
			cin >> x >> y;
			g[i][--x] = y;
		}
	}
	ll lim = pow(2, n);
	int max = 0;
	for (int i = 0; i < lim; i++)
	{
		bool f = false;
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j)))
				continue ;
			for (auto it = g[j].begin(); it != g[j].end(); it++)
			{
				if (it->second == 1 && !(i & (1 << it->first)))
					f = true;
				if (it->second == 0 && i & (1 << it->first))
					f = true;
			}
		}
		int honest = __builtin_popcount(i);
		if (!f && honest > max)
			max = honest;
	}
	cout << max << endl;
}

