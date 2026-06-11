#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int x[maxn], y[maxn], n;
ll cal(ll x) {
	return x * (x + 1) / 2;
}
int main() {
	scanf("%d",&n);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d%d",&x[i],&y[i]);
		if (x[i] > y[i]) swap(x[i],y[i]);
		ans += cal(i);
		ans -= 1ll * x[i] * (n - y[i] + 1);
	}
	printf("%lld\n",ans + cal(n));
	return 0;
}