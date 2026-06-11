#include <cstdio>

typedef long long ll;
ll arr[100010], s[100010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		scanf("%lld", arr + i);
	s[n] = arr[n];
	for (int i = n - 1; i >= 0; --i)
		s[i] = s[i + 1] + arr[i];
	ll ans = 0, cur = 1;
if (n == 0) {
puts(arr[0] == 1 ? "1" : "-1");
return 0;
}
	if (arr[0] || !arr[n]) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (cur > s[i + 1])
			cur = s[i + 1];
		if (cur * 2 < arr[i + 1]) {
			puts("-1");
			return 0;
		}
		ans += cur + arr[i];
		cur = cur * 2 - arr[i + 1];	
	}
	printf("%lld", ans + arr[n]);
	return 0;
}