#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>d(n);
	for (int i = 0; i < n; i++)cin >> d.at(i);
	if (d.at(0) != 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(d.begin(), d.end());
	vector<int>ds(d.at(n - 1) + 1, 0);
	for (int i = 0; i < n; i++)ds.at(d.at(i))++;
	//0排除
	if (ds.at(0) != 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < ds.size() - 1; i++) {
		if (ds.at(i) == 0 && ds.at(i + 1) != 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = 1;
	for (int i = 2; i < ds.size(); i++) {
		ans %= 998244353;
		for (int j = 0; j < ds.at(i); j++) {
			ans *= ds.at(i - 1);
			ans %= 998244353;
		}
		ans %= 998244353;
	}
	cout << ans << endl;
}