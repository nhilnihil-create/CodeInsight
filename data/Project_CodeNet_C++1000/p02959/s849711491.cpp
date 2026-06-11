#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, ans;
vector <int> a;
vector <int> b;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 0;
	cin >> n;
	for(int i = 0; i < n+1; ++i) {
		int x; cin >> x;
		a.pb(x);
	}
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		b.pb(x);
	}
	for(int i = 0; i < n; ++i) {
		ans += min(a[i], b[i]);
		if (b[i] - a[i] > 0) {
			ans += min(a[i+1], b[i]-a[i]);
			a[i+1] -= min(a[i+1], b[i]-a[i]);
		}
	}
	cout << ans;
}
