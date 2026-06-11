#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
const int N = 3e5+ 2, mod = 1e9 + 7;

void solve() {
     int x;
     cin >> x;
     cout << !x;
}    


int main() {
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout << "Case #:" << tc << " ";
		solve();
	}
}