/**
 *  author: nayakashutosh9
 *	[2020-09-22 19:29]
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define modd 998244353
#define inf 1e18
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/

struct cmp {
	bool operator()(pii a, pii b) {
		if (a.ff == b.ff) return a.ss < b.ss;
		return a.ff > b.ff;
	}
};
int n;
vector<pii> a;
int dp[2005][2005];
int check(int i, int p, int q) {
	if (i == n) return 0;
	if (dp[p][q] != -1) return dp[p][q];
	int cur = 0;
	cur = max(cur, a[i].ff * abs(a[i].ss - p) + check(i + 1, p + 1, q));
	cur = max(cur, a[i].ff * abs(q - a[i].ss) + check(i + 1, p, q - 1));
	return dp[p][q] = cur;
}
void solve() {
	cin >> n;
	a.clear(); a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].ff, a[i].ss = i;
	sort(all(a), cmp());
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = -1;
	}
	cout << check(0, 0, n - 1) << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}