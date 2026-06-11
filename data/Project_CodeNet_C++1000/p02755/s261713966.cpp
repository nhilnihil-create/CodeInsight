#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	int ans = -1;
	for (int i = 1; i <= 1300; i++) {
		if (i*8/100 == A && i*10/100 == B) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);

	return 0;
}
