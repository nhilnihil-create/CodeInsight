#include <bits/stdc++.h>

using namespace std;


int main(void)
{
	const long long p = 998244353;
	int n, s;
	cin >> n >> s;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long d[n+1][s+1];
	for (int j = 0; j <= s; j++) {
		if (a[0] == j)
			d[1][j] = 1;
		else
			d[1][j] = 0;
	}
	d[1][0] = 2;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			long long v = 0;
			v += d[i-1][j]*2;
			v %= p;
			if (j-a[i-1] >= 0) {
				v += d[i-1][j-a[i-1]];
				v %= p;
			}
			d[i][j] = v;
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/


	cout << d[n][s] << endl;

	return 0;
}