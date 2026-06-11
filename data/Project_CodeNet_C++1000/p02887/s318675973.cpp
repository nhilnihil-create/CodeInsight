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

int n;

void solve() {
	cin >> n;
	string s;
	cin >> s;

	int sze = 1;

	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) ++sze;
	}

	cout << sze;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}