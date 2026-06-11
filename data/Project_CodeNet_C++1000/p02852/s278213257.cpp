#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

int n, m;

void solve() {
	cin >> n >> m;
	vector<char> s(n + 1);

	for (int i = 0; i <= n; ++i) {
		cin >> s[i];
	}

	vector<int> pos;

	for (int i = 0; i <= n; ++i) {
		if (s[i] == '0') pos.push_back(i);
	}

	int up = n;

	deque<int> ans;
	ans.push_front(n);

	while (up > 0) {
		auto it = lower_bound(pos.begin(), pos.end(), up - m);
		if (it == pos.end()) {
			cout << -1;
			return;
		}

		if (*it >= up) {
			cout << -1;
			return;
		}

		up = *it;
		ans.push_front(*it);
	}

	vector<int> res;
	int prev = 0;

	// for (auto &c : ans) cout << c << ' ';
	// cout << '\n';

	for (int i = 1; i < Size(ans); ++i) {
		res.push_back(ans[i] - ans[i - 1]);
	}

	for (auto &c : res) cout << c << ' ';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}