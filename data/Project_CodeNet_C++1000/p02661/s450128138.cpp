#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const ll inf = 1e9;
const ll INF = 2e18; 
const int N = 6e6 + 66;
const int M = 1015;

int l[N], r[N];

void solve () {
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; ++ i) cin >> l[i] >> r[i];
	sort (l + 1, l + 1 + n), sort (r + 1, r + 1 + n), reverse (r + 1, r + 1 + n);
	int h = (n + 1) / 2;
	int L = (n % 2 ? l[h] : l[h] + l[h + 1]), R = (n % 2 ? r[h] : r[h] + r[h + 1]);
	cout << R - L + 1;
}

int main (/*UwU*/) {
	ios;
	int tt = 1;
	// cin >> tt;
	while (tt-- || 0) {
		solve();
		cout << "\n";
	}
}