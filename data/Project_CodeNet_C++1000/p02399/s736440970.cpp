#include <cstdio>
using namespace std;

int main (void)
{
	int a, b, r, d;
	double f, i, j;

	scanf("%d %d", &a, &b);

	d = a / b;
	r = a % b;

	i = a;
	j = b;

	f = i / j;

	printf("%d %d %lf\n", d, r, f);

	return 0;
}