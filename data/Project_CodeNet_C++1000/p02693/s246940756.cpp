#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(void) {
	int K, A, B;
	scanf("%d %d %d", &K, &A, &B);
	bool ans = false;
	for (int i = A; i <= B; i++) {
		if (i % K == 0) ans = true;
	}
	printf(ans ? "OK" : "NG");

	return 0;
}
