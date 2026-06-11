#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll x = 0;
	for (int i = 0; i < n; i++) {
		x = a[i] * 2 - x;
	}
	x /= 2;
	vector<int> ans(n);
	ans[0] = x;
	for (int i = 1; i < n; i++) {
		ans[i] = (a[i - 1] - ans[i - 1] / 2) * 2;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i == n - 1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}