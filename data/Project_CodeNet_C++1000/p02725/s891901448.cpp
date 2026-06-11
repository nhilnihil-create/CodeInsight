#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int k, n, x, y; cin >> k >> n;
	vector<int> a(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		if (i == 0) continue;
		d.at(i - 1) = a.at(i) - a.at(i - 1);
	}
	d.at(n - 1) = a.at(0) + (k - a.at(n - 1));
	sort(d.begin(), d.end());
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += d.at(i);
	}
	cout << ans << endl;
}