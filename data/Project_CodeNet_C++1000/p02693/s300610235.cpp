#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int K, A, B;
	(void)scanf("%d%d%d", &K, &A, &B);
	bool ans = true;
	int i = 1;
	while (ans) {
		if (A > i * K) {
			i++;
			continue;
		}
		else if (B < i * K) {
			ans = false;
			break;
		}
		else break;
	}
	if (ans)printf("OK"); else printf("NG");
}