#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 2e5 + 5;

int n;
int d[N];
ll c[N];

int main() {
	scanf("%d", &n);
	ll ans = -1, sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%lld", d + i, c + i);
		ans += c[i];
		sum += d[i] * c[i];
	}
	ans += sum / 9;
	sum %= 9;
	while (sum + 9 < 10)
		ans--, sum += 9;
	printf("%lld\n", ans);
	return 0;
}
