#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n, t;
	cin >> n >> t;
	vll a(n), b(n);
	for (ll i = 0; i < n; i++) cin >> a[i] >> b[i];

	vector<vll> dp1(n - 1, vll(t, 0));
	if (a[0] < t) {
		dp1[0][a[0]] = b[0];
		for (ll i = a[0] + 1; i < t; i++) dp1[0][i] = dp1[0][i - 1];
	}
	for (ll i = 1; i < n - 1; i++) {
		dp1[i] = dp1[i - 1];
		for (ll j = a[i]; j < t; j++) {
			dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i]] + b[i]);
		}
	}

	vector<vll> dp2(n, vll(t, 0));
	if (a[n - 1] < t) {
		dp2[n - 1][a[n - 1]] = b[n - 1];
		for (ll i = a[n - 1] + 1; i < t; i++) dp2[n - 1][i] = dp2[n - 1][i - 1];
	}
	for (ll i = n - 2; i > 0; i--) {
		dp2[i] = dp2[i + 1];
		for (ll j = a[i]; j < t; j++) {
			dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i]] + b[i]);
		}
	}

	priority_queue<ll> ans;
	ans.push(dp2[1][t - 1] + b[0]);
	ans.push(dp1[n - 2][t - 1] + b[n - 1]);

	for (ll i = 1; i < n - 1; i++) {
		ll x = 0;
		for (ll j = 0; j < t; j++) {
			x = max(x, dp1[i - 1][j] + dp2[i + 1][t - 1 - j]);
		}
		ans.push(x + b[i]);
	}

	cout << ans.top() << endl;
}
