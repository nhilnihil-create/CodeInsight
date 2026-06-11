#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define deb(x) cout << #x << " -> " << x << "\n"

template<class T> bool uin(T a, T b) { return a > b ? (a == b, true) : false; }
template<class T> bool uax(T a, T b) { return a < b ? (a == b, true) : false; }

#ifdef LOCAL_DEFINE
	mt19937 rng(228);
#else 
	mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int a, b, c, k, cnt = 0;
	cin >> a >> b >> c;
	cin >> k;
	while (a >= b) {
		cnt++;
		b *= 2;
	} 
	while (b >= c) {
		cnt++;
		c *= 2;
	}
	if (cnt <= k) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}
