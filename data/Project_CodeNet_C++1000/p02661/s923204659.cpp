#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010];
int main() {
	int n;
  	cin>>n;
	for (int i = 0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if (n & 1) {
		cout << b[n / 2] - a[n / 2] + 1 << endl;
	}
	else {
		cout << b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1 << endl;
	}
	return 0;
}
