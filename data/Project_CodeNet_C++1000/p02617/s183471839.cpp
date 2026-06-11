#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int n, u, v;

ll ans;

int main() {
	scanf("%d", &n); ans = 1ll * n * (n + 1) * (n + 2) / 6ll;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		ans -= 1ll * u * (n - v + 1);
	}  printf("%lld", ans);
	return 0;
}