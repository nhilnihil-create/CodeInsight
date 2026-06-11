#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	ll l = -1;
	ll r = a.at(0) * 2+1;
	vector<ll>ans(n);
	while (r - 1 > l) {
		vector<ll>ac = a;
		ll mid = (r + l) / 2;
		mid *= 2;
		//cout << "mid:" << mid << " l:" << l << " r:" << r << endl;
		ac.at(0) -= mid / 2;
		ac.at(n - 1) -= mid / 2;
		ans.at(0) = mid;
		bool f = true;
		ll minpos = -1;
		for (int i = n - 1; i >= 1; i--) {
			if (ac.at(i) < 0) {
				minpos = i;
				break;
			}
			ans.at(i) = ac.at(i) * 2;
			ac.at(i - 1) -= ac.at(i);
			ac.at(i) = 0;
			if (ac.at(i - 1) < 0) {
				minpos = i - 1;
				break;
			}
		}
		if (minpos % 2 == 0)f = false;
		if (f) {
			if (ac.at(0) > 0)l = mid/2;
			else {
				r = mid/2;
				break;
			}
		}
		else r = mid/2;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0)cout << ans.at(i);
		else cout << " " << ans.at(i);
	}
}