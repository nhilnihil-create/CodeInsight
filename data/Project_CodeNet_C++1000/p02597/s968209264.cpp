#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	int zeronum = 0;
	for (int i = 0;i < n;i++) {
		char c;
		cin >> c;
		if (c == 'R') {
			a[i] = 0;
			zeronum += 1;
		} else {
			a[i] = 1;
		}
	}
	int zeros = 0, ones = 0;
	int ans = 10000000;
	for (int i = 0;i <= n;i++) {
		int m = 0;
		if (zeronum - zeros > ones) {
			m = zeronum - zeros;
		} else {
			m = ones;
		}
		//cout << i << " " << m << endl;
		if (m < ans) {
			ans = m;
		}
		if (i < n) {
			if (a[i] == 0) {
				zeros += 1;
			} else {
				ones += 1;
			}
		}
	}
	cout << ans << endl;
}
