#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 5;
int n, k;
int a[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int s = 1, e = 1e9, ans;
	while (s <= e) {
		int mid = s + e >> 1;
		auto check = [&](int minlen) {
			int cut = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] <= minlen) continue;
				cut += a[i] / minlen;
			}
			return cut <= k;
		};
		if (check(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return !printf("%d\n", ans);
}