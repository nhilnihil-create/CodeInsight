#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

signed main () {
	int n, m;
	cin >> n >> m;
	vector < bool > b(n + 1, 0);
	for (int i = 0; i <= n; ++i) {
		char s;
		cin >> s;
		b[i] = (s == '1');
	}
	vector < int > pos = {n};
	bool zelimkhan_bakaev = 0;
	while (pos.back() != 0) {
		int nxt = -1;
		for (int j = pos.back() - 1; j >= max(pos.back() - m, 0); --j) {
			if (!b[j])
				nxt = j;
		}
		if (nxt == -1) {
			zelimkhan_bakaev = 1;
			break;
		}
		else
			pos.push_back(nxt);
	}
	if (zelimkhan_bakaev)
		cout << "-1\n";
	else {
		reverse(pos.begin(), pos.end());
		for (int i = 1; i < int(pos.size()); ++i)	
			cout << pos[i] - pos[i - 1] << ' ';
		cout << '\n';
	}
}
