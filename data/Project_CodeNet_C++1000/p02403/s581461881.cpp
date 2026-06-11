#include <stdio.h>
int main()
{
	int h, w, i, j;
	while (1)
	{
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0) {
			return 0;
		}
		else {
			for (i = 1;i <= h;i++) {
				for (j = 1;j <= w;j++) {
					printf("#");
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}