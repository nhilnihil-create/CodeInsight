#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if (n % 2 == 0) {
		int min2 = (a[n/2-1] + a[n/2]);
		int max2 = (b[n/2-1] + b[n/2]);
		cout << max2 - min2 +1 << endl;
	} else {
		int min = a[n/2];
		int max = b[n/2];
		cout << max-min+1 << endl;
	}

	return 0;
}
