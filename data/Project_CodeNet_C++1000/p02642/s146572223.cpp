#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int M = 1e6 + 5;
int n;
int a[N], cnt[M];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		auto divi = [&](int i) {
			for (ll j = 1; j * j <= a[i]; j++) {
				if (a[i] % j == 0) {
					if (cnt[j] >= 1 + (a[i] == j)) return false;
					if (cnt[a[i] / j] >= 1 + (a[i] / j == a[i])) return false;
				}
			}
			return true;
		};
		ans += divi(i);
	}
	printf("%d\n", ans);
}