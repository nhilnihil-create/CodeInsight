#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ff first
#define ss second
#define debug(x) cerr<<#x<<" : "<<x<<endl;
#define dbg2(x, y) cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define dbg3(x, y, z) cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl;
#define debugv(v) cerr <<endl; for(int i = 0; i<(int)(v.size()); i++){ cerr<<#v<<"["<<i<<"] = "<<v[i]<<endl;} cerr<<endl;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define MOD 1000000007
#define BIGMOD 32361122672259149LL

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//functions - find_by_order(index) - returns iterator, order_of_key(key) - number of values less than key
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll md(ll a) {
	return ((a%MOD)+MOD)%MOD;
}

ll po(ll a, ll b) {
	if (b==0) return 1LL;
	ll x = po(a, b>>1);
	x = md(x*x);
	if (b&1) x = md(x*a);
	return x;
}

void solve() {
	ll a, b, c, k;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
	if (a>=k) {
		cout << k << endl;
	} else if ((a+b)>=k) {
		cout << a << endl;
	} else {
		cout << a-(k-(a+b)) << endl;
	}

}	

int main() {
	#ifdef LOCAL
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);


	int num_tests = 1;
	// scanf("%d ", &num_tests);
	// cin>>num_tests;

	for (int tc=1; tc<=num_tests; tc++) {
		// printf("Case #%d: ", tc);
		// cout << "Case #" << tc << ": ";
		solve();
	}
	printclock
	return 0;
}