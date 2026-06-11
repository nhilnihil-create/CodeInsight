#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int K, X;
	scanf("%d %d", &K, &X);
	printf(500 * K >= X ? "Yes" : "No");

	return 0;
}
