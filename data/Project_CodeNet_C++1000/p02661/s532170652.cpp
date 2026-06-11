#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxn = 2e5 + 5;
int n;
int a[maxn], b[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", a + i, b + i);
	sort(a, a + n); sort(b, b + n);
	if (n % 2 == 1) {
		printf("%lld\n", (ll)b[n / 2] - a[n / 2] + 1);
	}
	else {
		printf("%lld\n", (ll)b[n / 2 - 1] + b[n / 2] - a[n / 2 - 1] - a[n / 2] + 1);
	}

	return 0;
}