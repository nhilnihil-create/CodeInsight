#include <iostream>
#include <cstdio>
#define N 1000000007
#define lll long long
using namespace std;
lll q(lll a, lll p)
{
	lll ans = 1;
	while (p)
	{
		if (p % 2)
	    ans = ans * a % N;
	    a = a * a % N;
	    p >>= 1;
	}
	return ans%N;
}
int main()
{
	lll n;
	scanf ("%lld", &n);
	printf ("%lld", ( (q(10ll, n) - q(9ll, n) * 2 )%N+ q(8ll, n)%N +N)%N );
	return 0;
}
