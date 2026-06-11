#include <cstdio>

int main()
{
	int hash[100001];
	int i;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		hash[a] = i+1;
	}

	for (i = 1; i < n+1; i++) {
		printf("%d ", hash[i]);
	}
	return 0;
}
