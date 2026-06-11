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


int x, y, z;

void input() {
	cin >> x >> y >> z;
}

void solve() {
	swap(x, y);
	swap(x, z);

	cout << x << ' ' << y << ' ' << z;	
}

signed main() {
#ifdef _DEBUG
	freopen("INPUT.inp", "r", stdin);
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