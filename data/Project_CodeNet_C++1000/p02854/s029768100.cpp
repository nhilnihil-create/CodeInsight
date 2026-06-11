#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);

	vector<ll>s(n);
	s.at(0) = a.at(0);
	for (int i = 1; i < n; i++)s.at(i) = s.at(i - 1) + a.at(i);

	double mid = s.at(n - 1) * 0.5;
	int x = lower_bound(s.begin(), s.end(),mid) - s.begin();
	if (x == s.at(n - 1) * 0.5) {
		cout << 0 << endl;
		return 0;
	}
	double l = mid - s.at(x - 1);
	double r = s.at(x) - mid;
	int ans = min(l, r) * 2;
	cout << ans << endl;
}