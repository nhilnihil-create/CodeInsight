#include <stdio.h>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	long long n, k; scanf ("%lld %lld", &n, &k);
	n %= k;
	if (n > k - n)
		n = k - n;
	printf ("%lld\n", n);

	return 0;
}