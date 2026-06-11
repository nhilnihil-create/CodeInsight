#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf((A == B && A == C) || (A != B && A != C && B != C) ? "No" : "Yes");

	return 0;
}
