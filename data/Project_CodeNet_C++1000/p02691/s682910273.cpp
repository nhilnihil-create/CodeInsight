#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n;
	ll ans = 0;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> m;
	rep(i, n) {
		int low = i + a[i];
		int high = i - a[i];
		ans += m[high];
		m[low]++;
	}
	cout << ans << endl;
	return 0;
}
// (x > y) x - a[x] = y + a[y]
// x[1] = 4, x[7] = 2, x[8] = 3
// x[7] = 2; x[11] = 2
