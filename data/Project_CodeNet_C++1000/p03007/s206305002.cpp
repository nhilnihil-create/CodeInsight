#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int a[n], sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	if (a[0] >= 0) {
		cout << sum - a[0] * 2 << endl;
		rep(i, n - 2) {
			cout << a[0] << " " << a[i + 1] << endl;
			a[0] -= a[i + 1];
		}
		cout << a[n - 1] << " " << a[0] << endl;
	} else if (a[n - 1] <= 0) {
		reverse(a, a + n);
		cout << -sum + a[0] * 2 << endl;
		rep(i, n - 1) {
			cout << a[0] << " " << a[i + 1] << endl;
			a[0] -= a[i + 1];
		}
	} else {
		sum = 0;
		rep(i, n) sum += abs(a[i]);
		cout << sum << endl;
		int p = upper_bound(a, a + n, 0) - a;
		for (int i = 1; i < p; i++) {
			cout << a[p] << " " << a[i] << endl;
			a[p] -= a[i];
		}
		for (int i = p; i < n - 1; i++) {
			cout << a[0] << " " << a[i] << endl;
			a[0] -= a[i];
		}
		cout << a[n - 1] << " " << a[0] << endl;
	}
	return 0;
}