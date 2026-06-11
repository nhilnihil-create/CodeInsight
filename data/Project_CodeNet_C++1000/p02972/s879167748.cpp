#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(n, 0);

	for (int i = n; i >= 1; i--) {
		int tmp = 0;
		for (int j = i+i; j <= n; j += i) {
			tmp += b[j-1];
		}
		if (tmp % 2 == a[i-1]) {
			b[i-1] = 0;
		} else {
			b[i-1] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b[i];
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		if (b[i])
			cout << i+1 << endl;
	}
	return 0;
}