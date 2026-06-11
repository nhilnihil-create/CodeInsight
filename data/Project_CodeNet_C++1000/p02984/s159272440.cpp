#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	long long sum = 0;
	long long sum_plus_y0 = 0;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (i%2 == 0)
			sum_plus_y0 += a[i];
	}
	long long y[n];
	y[0] = 2*sum_plus_y0 - sum;
	for (int i = 1; i < n; i++) {
		y[i] = 2 * a[i-1] - y[i-1];
	}
	for (int i = 0; i < n; i++) {
		printf("%lld", y[i]);
		if (i < n-1)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}