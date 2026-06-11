#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>xl(n, vector<int>(2));
	for (int i = 0; i < n; i++)cin >> xl.at(i).at(0) >> xl.at(i).at(1);
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	sort(xl.begin(), xl.end());
	ll ans = 0;
	ll l = -10000000000, r = -10000000000;
	for (int i = 0; i < n; i++) {
		ll nl = xl.at(i).at(0) - xl.at(i).at(1);
		ll nr = xl.at(i).at(0) + xl.at(i).at(1);
		if (r <= nl) {
			ans++;
			l = nl;
			r = nr;
		}
		else if (nr <= r) {
			l = nl;
			r = nr;
		}
		//cout << ans << nl << nr << endl;
	}
	cout << ans << endl;
}