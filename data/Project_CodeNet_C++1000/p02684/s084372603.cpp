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
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int time = 1, cur = 1;
	unordered_map<int, int> vis;
	int st = 0, ed = 0;
	while (!(vis.count(cur))) {
		vis[cur] = time++;
		cur = a[cur];
	}
	ed = time; st = vis[cur];
	if (k <= st - 1) {
		int ans = 1;
		while (k > 0) {
			ans = a[ans];
			k--;
		}
		cout << ans << endl;
	}
	else {
		k -= (st - 1);
		k %= (ed - st);
		int ans = cur;
		while (k > 0) {
			ans = a[ans];
			k--;
		}
		cout << ans << endl;
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