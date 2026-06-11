#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL T, A, X, B, Y;

int main()
{
	scanf("%lld %lld", &A, &X);
	scanf("%lld %lld", &B, &Y);
	scanf("%lld", &T);

	if((X - Y) * T >= abs(A - B)) puts("YES");
	else puts("NO");
	return 0;
}
