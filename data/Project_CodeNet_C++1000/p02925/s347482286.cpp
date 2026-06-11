#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
using namespace std;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector < vector < int > > a(n + 1, vector < int > (n - 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - 1; ++j)
			cin >> a[i][j];
	}
	vector < int > pointers(n + 1, 0);
	int days = 0;
	bool fucked_up = 0;
	while (true) {
		bool moves = 0;
		vector < bool > played(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			if (pointers[i] < n - 1) {
				int j = a[i][pointers[i]];
				if (pointers[j] < n - 1 && a[j][pointers[j]] == i && !played[i] && !played[j]) {
					++pointers[i];
					++pointers[j];
					played[i] = 1;
					played[j] = 1;
					moves = 1;
				}
			}
		}
		++days;
		if (!moves)
			fucked_up = 1;
		bool johny_b_good = 1;
		for (int i = 1; i <= n; ++i) {
			if (pointers[i] != n - 1)
				johny_b_good = 0;
		}
		if (fucked_up || johny_b_good)
			break;
	}
	if (fucked_up)
		days = -1;
	cout << days << '\n';
}
