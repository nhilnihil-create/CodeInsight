#include<cstdio>
using namespace std;

int main(void) {
	int X, A;
	scanf("%d %d", &X, &A);
	if (X < A) {
		printf("%d\n", 0);
	} else {
		printf("%d\n", 10);
	}

	return 0;
}
