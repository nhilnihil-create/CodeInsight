#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100

int main(void)
{
	int n, a[MAX], i = 0;
	do {
		cin >> n;
	} while (n > MAX || n < 0);

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	while (1) {
		printf("%d", a[n - i - 1]);
		if (i++ == n - 1) break;
		printf(" ");
	}
	printf("\n");
	return 0;
}