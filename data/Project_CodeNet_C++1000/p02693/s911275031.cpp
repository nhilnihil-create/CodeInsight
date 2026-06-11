#include <stdio.h>

int main() {
	int fold, dist1, dist2;
	scanf("%d", &fold);
	scanf("%d %d", &dist1, &dist2);
	while (dist1 <= dist2) {
		if(dist1 % fold == 0) {
			printf("OK");
			return 0;
		}
		dist1++;
	}
	printf("NG");
	return 0;
}