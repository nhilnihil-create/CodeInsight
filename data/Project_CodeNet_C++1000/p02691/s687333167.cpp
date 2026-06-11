// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int aa[N * 2];

int main() {
	int n; cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		int x = a + i, y = i - a;
		aa[m++] = x << 1;
		if (y > 0)
			aa[m++] = y << 1 | 1;
	}
	n = m;
	sort(aa, aa + n);
	long long ans = 0;
	for (int i = 0, j, k; i < n; i = k) {
		int a = aa[i] >> 1;
		j = i;
		while (j < n && aa[j] == (a << 1))
			j++;
		k = j;
		while (k < n && aa[k] == (a << 1 | 1))
			k++;
		ans += (long long) (j - i) * (k - j);
	}
	cout << ans << '\n';
	return 0;
}
