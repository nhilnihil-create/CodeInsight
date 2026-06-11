#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N, R;
	scanf("%d %d", &N, &R);

	if (N >= 10) {
		printf("%d", R);
	} else {
		printf("%d", R + 100 * (10 - N));
	}
	return 0;
}
