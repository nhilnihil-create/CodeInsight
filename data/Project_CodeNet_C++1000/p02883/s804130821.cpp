#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

int n;
ll k, a[N], b[N];

bool f(ll lim) {
	ll req = 0;

	for(int i = 0; i < n; i++) {
		req += max(0LL, a[i] - lim / b[i]);
	}

	return req <= k;
}

int main() {
	scanf("%d %lld", &n, &k);
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	for(int i = 0; i < n; i++) scanf("%lld", b + i);
	sort(a, a + n);
	sort(b, b + n); reverse(b, b + n);

	ll lo = 0, hi = 1e13, ans = -1;
	while(lo <= hi) {
		ll mid = (lo + hi) / 2;
		if(f(mid)) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	printf("%lld\n", ans);
}
