#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n, greater <int> ());
	long long ans = 0;
	for (int i = 1; i < n; ++i)
		ans += a[i >> 1];
	printf("%lld\n", ans);
	return 0;
}

