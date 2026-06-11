#include <cstdio>
using namespace std;

int main() 
{
	int a, b, k;
	scanf("%d%d%d", &k, &a, &b);
	if ((a - 1) / k * k + k <= b) printf("OK\n");
	else printf("NG\n");
	return 0;
}
