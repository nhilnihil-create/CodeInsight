#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define For(i,x,y) for(int i = x; i <= y; ++i)
#define FOR For
#define rev_For(i,x,y) for(int i = x; i >= y; --i)
#define REV_FOR rev_For
#define ll long long
#define Size(v) ((int)v.size())
#define _section "\n--------------------\n"
#define fi first
#define se second
#define pb push_back
using namespace std;
// using namespace __gnu_pbds;


int n, k;
const int MOD = 1e9 + 7;
const int nax = 1e5 + 5;
int store[nax];

int binpow(int x, int y) {
	if (y == 0) return 1 % MOD;
	if (y == 1) return x % MOD;

	if (y & 1) {
		int mid = binpow(x, y / 2);
		return ((mid * mid) % MOD * x) % MOD;
	}
	else {
		int mid = binpow(x, y / 2);
		return (mid * mid) % MOD;
	}
}

void input() {
	cin >> n >> k;
}

void solve() {
	int sum = 0;
	// xet so bi chia
	for (int i = k; i >= 1; --i) {
		int high = k / i;
		store[i] = binpow(high, n);

		int j = i;
		for (int t = 2; j * t <= k; ++t) {
			int temp = j * t;
			// cout << i << ' ' << temp << '\n';

			store[i] -= store[temp];
		}
	}

	for (int i = 1; i <= k; ++i) {
		sum = (sum + store[i] * i) % MOD;
	}

	cout << sum;
}

signed main() {
#ifdef _DEBUG
	// freopen("INPUT.inp", "r", stdin);
	//freopen("OUTPUT.out", "w", stdout);
	clock_t start, end;
	start = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//------------------------------------------------------------------------------------
//----------------------------------MAIN PROGRAM--------------------------------------
	int t = 1;
	while (t--) {
		input();
		solve();
	}
//--------------------------------------END-------------------------------------------
//------------------------------------------------------------------------------------
#ifdef _DEBUG
	end = clock();
	cerr << "\n----------\nTime Elapsed: " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(6) << '\n';
#endif
	return 0;
}