#include <cstdio>
using namespace std;

int main() 
{
	int a, b, c, k;
	scanf("%d%d%d%d", &a, &b, &c, &k);
	if (k <= a) printf("%d\n", k);
	else if (k <= a + b) printf("%d\n", a);
	else printf("%d\n", 2 * a - k + b);
	return 0;
}
