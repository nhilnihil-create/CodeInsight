#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
const ll MOD = 998244353;
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 100100;
int a[N];
using namespace std;
int main()
{

	int n;
	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	if (x != 0) {
		printf("0\n");
		return 0;
	}
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	if (a[0] != 1) {
		printf("0\n");
		return 0;
	}
	while(a[n] == 0) n--;
	ll ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < a[i + 1]; j++)
			ans = mult(ans, a[i]);
	printf("%lld\n", ans);

	return 0;
}
