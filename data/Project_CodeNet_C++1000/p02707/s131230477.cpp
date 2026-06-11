#include <cstdio>
#define MAX 200002
int main()
{
	int a[MAX];

	int i;
	for (i = 0; i < MAX; i++) {
		a[i] = 0;
	}

	int n;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		int d;
		scanf("%d", &d);
		a[d]++;
	}	

	for (i = 1; i <= n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}