#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, k;
	cin >> n >> k;
	if (k * 2 > (n - 1) * (n - 2))
		cout << "-1\n";
	else {
		vector < pair < int, int > > edges;
		for (int i = 2; i <= n; ++i)
			edges.push_back(make_pair(1, i));
		int cur = ((n - 1) * (n - 2)) / 2;
		vector < set < int > > can(n + 1);
		for (int i = 2; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) 
				can[i].insert(j);
		}
		int i = 2;
		while (cur > k) {
			if (can[i].empty())
				++i;
			edges.push_back(make_pair(i, *can[i].begin()));
			can[i].erase(can[i].begin());
			--cur;
		}
		cout << edges.size() << '\n';
		for (int j = 0; j < int(edges.size()); ++j)
			cout << edges[j].first << ' ' << edges[j].second << '\n';
	}
}
