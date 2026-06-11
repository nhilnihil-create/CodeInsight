#include <cstdio>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int i;
	int count;
	for (i = 0, count = 0; i < n; i++) {
		int h;
		scanf("%d", &h);
		if (h >= k)
			count++;
	}
	printf("%d\n", count);
}
