#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
ll lea[N], sum[N], a[N], ans = 1;
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)scanf("%lld", &lea[i]);
	if (lea[0] > 1) { puts("-1"); return 0; }
	for (int i = n; i >= 0; i--)sum[i] = sum[i + 1] + lea[i];
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (lea[i] > 2 * (a[i - 1] - lea[i - 1])) { puts("-1"); return 0; }
		a[i] = min(2 * (a[i - 1] - lea[i - 1]), sum[i]);
		ans += a[i];
	}
	printf("%lld\n", ans);
	return 0;
}