#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int L[100005];
int main() {
	int n, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		L[a] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			printf("%d\n", L[i]);
		}
		else printf("%d ", L[i]);
	}

	return 0;
}
