#include <bits/stdc++.h>
using namespace std;

signed main () {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	map < char, vector < int > > nxt;
	for (int i = 0; i < n; ++i) 
		nxt[s[i]].push_back(i);
	int64_t ans = 0;
	int i = 0;
	bool fucked = 0;
	while (i < m) {
		int j = -1;
		while (j < n && i < m) {
			ans -= j + 1;
			if (nxt[t[i]].empty()) {
				fucked = 1;
				break;
			}
			else {
				auto it = upper_bound(nxt[t[i]].begin(), nxt[t[i]].end(), j);
				if (it == nxt[t[i]].end())
					break;
				else {
					j = *it;
					ans += j + 1;
				}
				++i;
			}
		}
		if (i == m || fucked)
			break;
		else
			ans += n;
	}
	if (fucked)
		ans = -1;
	cout << ans << '\n';
}
