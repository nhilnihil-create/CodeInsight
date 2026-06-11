// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int ii[N + 1], ll[N + 2], rr[N + 2];
bool used[N + 2];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		ii[a] = i;
	}
	long long ans = 0;
	for (int a = 1; a <= n; a++) {
		int i = ii[a], l = i, r = i;
		used[i] = true;
		if (used[l - 1])
			l = ll[l - 1];
		if (used[r + 1])
			r = rr[r + 1];
		rr[l] = r, ll[r] = l;
		if (r < n) {
			int p = i - l + 1;
			int q = used[r + 2] ? rr[r + 2] - r : 1;
			ans += (long long) p * q * a;
		}
		if (l > 1) {
			int p = used[l - 2] ? l - ll[l - 2] : 1;
			int q = r - i + 1;
			ans += (long long) p * q * a;
		}
	}
	cout << ans << '\n';
	return 0;
}
