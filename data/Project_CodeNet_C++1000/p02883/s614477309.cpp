// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int aa[N], ff[N];

int main() {
	int n; cin >> n;
	long long k; cin >> k;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	for (int i = 0; i < n; i++)
		cin >> ff[i];
	sort(aa, aa + n);
	sort(ff, ff + n);
	long long lower = -1, upper = (long long) aa[n - 1] * ff[n - 1];
	while (upper - lower > 1) {
		long long x = (lower + upper) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int a = aa[i], f = ff[n - 1 - i];
			sum += max(a - x / f, 0LL);
		}
		if (sum <= k)
			upper = x;
		else
			lower = x;
	}
	cout << upper << '\n';
	return 0;
}
