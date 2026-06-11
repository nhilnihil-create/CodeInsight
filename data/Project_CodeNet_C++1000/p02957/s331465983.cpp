#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	if(a % 2 != b % 2) printf("IMPOSSIBLE\n");
	else {
		int ans = (a + b) / 2;
		printf("%d\n", ans);
	}
	return 0;
}