/*****************************************************
 *     created by: nayakashutosh9
 * "Winners Never Quit and Quitters Never Win".
*****************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define inf 1e18
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int N = 300005;
/**********************************************************************************************/


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
	int ans = 0;
	for (auto x : m) {
		if (x.second >= 2) {
			ans += (x.second * (x.second - 1) / 2);
		}
	}
	for (int i = 0; i < n; i++) {
		int g = ans, h = m[a[i]];
		if (h >= 2) g -= h * (h - 1) / 2;
		h--;
		if (h >= 2) g += h * (h - 1) / 2;
		cout << g << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1, z = 1;
	// cin >> t; cin.ignore();
	while (t--) {
		// cout << "Case #" << (z++) << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}