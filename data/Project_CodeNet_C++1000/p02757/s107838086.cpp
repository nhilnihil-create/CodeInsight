#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

int n, p, a[N], ps[N];

int mul(int aa, int bb) {
	return int(1LL * aa * bb % p);
}
int fexp(int b, int e = p - 2) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = mul(ans, b);
		b = mul(b, b);
		e /= 2;
	}
	return ans;
}

int cnt[N];

int main() {
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; i++) scanf("%1d", a + i);
	
	if(__gcd(10, p) == 1) {
		ll ans = 0;
		cnt[0] = 1;
		int pw = 1;
		for(int i = n; i >= 1; i--) {
			ps[i] = (a[i] * pw + ps[i + 1]) % p;
			ans += cnt[ ps[i] ];
			cnt[ ps[i] ]++;
			pw = 10 * pw % p;
		}

		printf("%lld\n", ans);
		return 0;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] % p == 0) {
			ans += i;
		}
	}
	printf("%lld\n", ans);
}
