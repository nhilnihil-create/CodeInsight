#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<int>b(n);
	for (int i = 0; i < n; i++)cin >> b.at(i);
	vector<int>c(n-1);
	for (int i = 0; i < n-1; i++)cin >> c.at(i);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b.at(a.at(i) - 1);
		if (i != 0) {
			if (a.at(i) - a.at(i - 1) == 1)ans += c.at(a.at(i - 1) - 1);
		}
	}
	cout << ans << endl;
}