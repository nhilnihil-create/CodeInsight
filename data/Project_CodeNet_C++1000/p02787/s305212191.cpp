#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int h, n;
	cin >> h >> n;
	long long a[n], b[n];
	long long max_a = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > max_a)
			max_a = a[i];
	}
	long long d[h+max_a];

	long long INF = 10e12;
	d[0] = 0;
	for (int i = 1; i < h+max_a; i++)
		d[i] = INF;
	for (int i = 1; i < h+max_a; i++) {
		long long min = INF;
		for (int j = 0; j < n; j++) {
			if (i-a[j] >= 0) {
				if (min > (d[i-a[j]] + b[j]))
					min = d[i-a[j]] + b[j];
			}
		}
		d[i] = min;
	}
	long long ans = INF;
	for (int i = h; i < h+max_a; i++) {
		if (d[i] < ans)
			ans = d[i];
	}
	cout << ans << endl;

	return 0;
}