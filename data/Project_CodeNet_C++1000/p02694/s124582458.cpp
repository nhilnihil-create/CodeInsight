#include <cstdio>
#include <cmath>
using namespace std;

int main() 
{
	long long x;
	scanf("%lld", &x);
	long long t = 100;
	int i;
	for (i = 0; t < x; ++i) t += t / 100;
	printf("%d\n", i);
	return 0;
}
