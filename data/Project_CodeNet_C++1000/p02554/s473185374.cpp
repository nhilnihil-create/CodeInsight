#pragma warning(disable:4996)
#include <stdio.h>
typedef long long ll;
ll MOD = 1000000007;
ll pow(ll a, ll n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	ll c = (pow(a, n / 2)) % MOD;
	ll temp = c * c % MOD;
	if (n % 2) return temp * a % MOD;
	else return temp;
}
int main()
{
	ll n;
	scanf("%lld", &n);
	printf("%lld", ((pow(10, n) - 2 * pow(9, n) + MOD * 2) % MOD + pow(8, n) % MOD) % MOD);
}