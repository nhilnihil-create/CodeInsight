
// Problem : C - Subarray Sum
// Contest : AtCoder - Keyence Programming Contest 2020
// URL : https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;	

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const ll maxN = 1e6 + 5;
const ll MOD = 1e9 + 7;

// sprawdz MODULO!
int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, s;
	cin >> n >> k >> s;
	REP(i, k) {
		cout << s << " ";
	}
	FOR(i, k, n - 1) {
		if (s == 1e9) cout << 1 << " ";
		else cout << s + 1 << " ";
	}
	return 0;
}
 
