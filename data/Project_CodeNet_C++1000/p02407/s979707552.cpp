#include <cstdio>
using namespace std;

int main (void)
{
	int data[101] = {0};
	int i, n, j;

	scanf("%d", &n);

	for (i=0; i<n; i++)
		scanf("%d", &data[i]);

	for (j=i-1; j>0; j--)
		printf("%d ", data[j]);
	printf("%d\n", data[0]);

	return 0;
}