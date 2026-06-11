#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n;
ll ans = 0;

int main() {
	scanf("%d", &n);
	rep(i, n) ans += 1LL * (i + 1) * (n - i);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u; -- v;
		if (u > v) swap(u, v);
		ans -= 1LL * (u + 1) * (n - v);
	}
	printf("%lld\n", ans);
	return 0;
}