#include<iostream>
using namespace std;

int n, a[20], x[20][20], y[20][20];

int counter(int rep) {
	return rep == 0 ? 0 : counter(rep >> 1) + (rep & 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= a[i]; j++) {
			cin >> x[i][j] >> y[i][j];
		}
	}

	int ans = 0;
	for (int b = 1; b < (1 << n); b++) {
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (!(b & (1 << i - 1)))continue;
			for (int j = 1; j <= a[i]; j++) {
				if ((b >> (x[i][j] - 1) & 1) ^ y[i][j])ok = false;
			}
		}
		if (ok)if (ans < counter(b))ans = counter(b);
	}
	cout << ans << endl;

	return 0;
}