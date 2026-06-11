#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	//input
	int A, B, C, K;
	(void)scanf("%d%d%d%d", &C, &B, &A, &K);

	//output
	bool ab, bc;
	if (A <= B)ab = false; else ab = true;
	if (B <= C)bc = false; else bc = true;
	for (int i = 0; i < K; i++) {
		if (ab && bc)break;
		if (ab == false) {
			A *= 2;
			if (A > B)ab = true;
			continue;
		}
		if (bc == false) {
			B *= 2;
			if (A <= B)ab = false;
			if (B > C)bc = true;
			continue;
		}
	}
	/*
	bool ab = false, bc = false;
	for (int i = 0; i < K; i++) {
		if (A <= B) {
			A *= 2;
		}
		else if (B <= C) {
			ab = true;
			B *= 2;
			if (A <= B)ab = false;
		}
		else {
			ab = true;
			bc = true;
			break;
		}
	}
	*/
	if (ab && bc)printf("Yes");
	else printf("No");
}