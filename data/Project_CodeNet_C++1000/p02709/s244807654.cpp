#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2005;

int n, a[N];
int id[N];

ll dp[N][N];

ll f(int l, int r) {
	int i = n - (r - l + 1);
	int p = id[i];
	if(l == r) return 1LL * a[p] * abs(p - l);
	ll &ans = dp[l][r];
	if(~ans) return ans;
	ans = -1e18;
	ans = max(ans, f(l + 1, r) + 1LL * a[p] * abs(p - l));
	ans = max(ans, f(l, r - 1) + 1LL * a[p] * abs(p - r));
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", a + i), id[i] = i;

	sort(id, id + n, [](int i, int j) {
		return a[i] > a[j];
	});

	printf("%lld\n", f(0, n - 1));
}
