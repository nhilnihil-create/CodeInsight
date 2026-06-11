#include <stdio.h>

int main() {
	int Zx, count = 0;
	int count1, count2;
	char Yz[104] = {};
	scanf("%d %s", &Zx, &Yz);
	if (Zx % 2 != 0) {
		printf("No");
		return 0;
	}
	int haafu = Zx / 2;
	for (int u = 0; u < haafu; u++) {
		if (Yz[u] == Yz[u + haafu]) {
			count++;
		}
	}
	count == haafu ? printf("Yes") : printf("No");

	return 0;
}