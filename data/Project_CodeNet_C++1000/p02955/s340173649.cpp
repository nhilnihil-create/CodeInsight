// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 500;

int aa[N], rr[N];

int count(int n, int md) {
	int rsum = 0;
	for (int i = 0; i < n; i++)
		rsum += rr[i] = aa[i] % md;
	if (rsum == 0)
		return 0;
	sort(rr, rr + n);
	int p = 0, q = n * md - rsum;
	for (int i = 0; i < n && p != q; i++) {
		p += rr[i];
		q -= md - rr[i];
	}
	return p;
}

int main() {
	int n, k; cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sum += aa[i] = a;
	}
	int ans = 0;
	for (int a = 1, b; a <= (b = sum / a); a++)
		if (sum % a == 0) {
			if (count(n, b) <= k) {
				ans = b;
				break;
			}
			if (count(n, a) <= k)
				ans = a;
		}
	cout << ans << '\n';
	return 0;
}
