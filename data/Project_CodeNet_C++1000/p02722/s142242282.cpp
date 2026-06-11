#include <stdio.h>
#include <set>
using namespace std;

set<long long> gat;

void test2(long long n)
{
	for (long long i = 1; i*i <= n; i++) if (n % i == 0){
		gat.insert(i);
		gat.insert(n / i);
	}
}

void test(long long i, long long n)
{
	if (i > 1){
		while (n % i == 0) n /= i;
		if (n % i == 1) gat.insert(i);
	}
}

int main()
{
	long long n; scanf ("%lld", &n);

	gat.insert(1);
	for (long long i = 1; i * i <= n; i++) if (n % i == 0){
		test(i, n);
		test(n / i, n);
	}

	test2(n - 1);

	printf ("%lld\n", gat.size() - 1);
	return 0;
}