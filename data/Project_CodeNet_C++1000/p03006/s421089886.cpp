#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<pair<ll,ll>>xy(n);
	set<pair<ll, ll>>xys;
	for (int i = 0; i < n; i++) {
		cin >> xy.at(i).first >> xy.at(i).second;
		xys.insert(xy.at(i));
	}
	sort(xy.begin(), xy.end());
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = 1000;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<ll, ll>v;
			v.first = xy.at(j).first - xy.at(i).first;
			v.second = xy.at(j).second - xy.at(i).second;
			ll res = n;
			for (int k = 0; k < n; k++) {
				pair<ll, ll> opt1 = { xy.at(k).first + v.first, xy.at(k).second + v.second };
				if (xys.count(opt1))res--;
			}
			ans = min(ans, res);
		}
	}
	cout << ans << endl;
}