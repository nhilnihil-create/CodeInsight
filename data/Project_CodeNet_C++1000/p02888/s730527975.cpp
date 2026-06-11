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
#define int long long
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

int n;
vector<int> a;

void solve() {
	cin >> n;

	a.resize(n + 1);

	for (int i = 1; i <= n; ++i) cin >> a[i];

	sort(a.begin() + 1, a.begin() + n + 1);

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		// choose a[i] as the max

		for (int j = 1; j < i; ++j) {
			// choose a[j] as the second max

			int m = a[i], s = a[j];

			// cerr << "m - s - i - j: " << m << ' ' << s << ' ' << i << ' ' << j << '\n';

			// s + k > m

			// cerr << "m: " << m << '\n';

			int k = m - s;

			auto it = upper_bound(a.begin() + 1, a.begin() + j, k);
			if (it == a.begin() + j) continue;
			else {
				// cerr << "*it: " << *it << '\n';
				int pos = a.begin() + j - it;
				ans += pos;

				// cerr << "pos: " << pos << '\n';
			}
		}
	}

	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}