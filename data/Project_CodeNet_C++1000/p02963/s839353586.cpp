#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL S;

int main()
{
	scanf("%lld", &S);
	int t = 1e9, a = S / t + (S % t == 0 ? 0 : 1), b = 1ll * a * t - S;
	printf("%d %d %d %d %d %d\n", 0, 0, t, b, 1, a);
	return 0;
}
