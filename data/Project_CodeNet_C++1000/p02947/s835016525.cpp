#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	map <string, ll> mp;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		sort(tmp.begin(), tmp.end());
		mp[tmp]++;
	}
	ll ans = 0;
	for (auto u : mp) {
		ans += u.second * (u.second - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}