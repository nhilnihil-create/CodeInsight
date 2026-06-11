#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int H, A;
	scanf("%d %d", &H, &A);
	printf("%d", (H - 1) / A + 1);

	return 0;
}
