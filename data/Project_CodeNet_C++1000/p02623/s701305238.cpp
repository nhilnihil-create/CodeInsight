#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	Abra_Ka_Dabra

	int n, m;
	ll k;
	cin >> n >> m >> k;
	vector<ll> x(n), y(m);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	for (int i = 1; i < n; i++) {
		x[i] += x[i - 1];
	}
	for (int i = 1; i < m; i++) {
		y[i] += y[i - 1];
	}
	int res = 0;
	for (int i = 0; i < n && x[i] <= k; i++) {
		int l = 0, r = m - 1, maxi = i + 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			ll tmp = x[i] + y[mid];
			if (tmp <= k) {
				maxi = i + mid + 2;
				l = mid + 1;
			} else r = mid - 1;
		}
		res = max(res, maxi);
	}
	for (int i = 0; i < m && y[i] <= k; i++) {
		int l = 0, r = n - 1, maxi = i + 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			ll tmp = y[i] + x[mid];
			if (tmp <= k) {
				maxi = i + mid + 2;
				l = mid + 1;
			} else r = mid - 1;
		}
		res = max(res, maxi);
	}
	cout << res << "\n";

	return 0;
}