#include <bits/stdc++.h>
using namespace std;

bitset<60> a[111111];
int main() {
	int n;
	cin >> n;
	long y = 0;
	for (int i = 0; i < n; i++) {
		long x;
		scanf("%ld", &x);
		y ^= x;
		a[i] = x;
	}
	for (int i = 0; i < n; i++)
		a[i] &= ~y;
	int r = [](bitset<60> *m, int R, int C) {
		int i = 0;
		for (int j = C; j--;) {
			int k;
			for (k = i; k < R; k++)
				if (m[k][j]) goto p;
			continue;
		p:
			swap(m[k], m[i]);
			for (k = 0; k < R; k++)
				if (k != i && m[k][j])
					m[k] ^= m[i];
			i++;
		}
		return i;
	}(a, n, 60);
	long x = 0;
	for (int i = 0; i < r; i++)
		if (x < (x^a[i].to_ulong()))
			x ^= a[i].to_ulong();
	cout << x + x + y << endl;
	return 0;
}
