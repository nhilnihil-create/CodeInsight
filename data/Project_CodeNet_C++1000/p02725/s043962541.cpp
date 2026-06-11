#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int k, n; cin >> k >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n - 1, 0);
	d[0] = k - a[n - 1] + a[0];
	for (int i = 1; i < n - 1; i++) {
		d[i] = a[i + 1] - a[i];
	}
	sort(d.rbegin(), d.rend());
	cout << k - d[0] << endl;
	return 0;
}