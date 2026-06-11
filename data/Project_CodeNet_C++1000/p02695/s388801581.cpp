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
struct dt {
	int a, b, c, d;
};
int n, m, q, ans;
vector<dt> a;
vector<int> val;
void check(int i, int st) {
	if (i == n) {
		int cur = 0;
		for (int j = 0; j < q; j++) {
			if (val[a[j].b - 1] - val[a[j].a - 1] == a[j].c) cur += a[j].d;
		}
		ans = max(ans, cur);
		return;
	}
	for (int j = st; j <= m; j++)
		val[i] = j, check(i + 1, j);
}
void solve() {
	cin >> n >> m >> q;
	a.clear(); a.resize(q);
	for (int i = 0; i < q; i++)
		cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
	ans = 0; val.clear(); val.resize(n, 0);
	check(0, 1);
	cout << ans << endl;
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