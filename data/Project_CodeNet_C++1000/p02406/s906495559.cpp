#include<stdio.h>
int main() {
	int n;
	int i = 1;
	int x;
	scanf("%d", &n);
	do {
		if (i % 3 == 0 || i % 10 == 3) {
			printf(" %d", i);
		}
		else
		{
			x = i;
			do
			{
				x /= 10;
				if (x%10==3)
				{
					printf(" %d",i);
					break;
				}
			} while (x>=10);
			
		}
		i += 1;
	} while (i <= n);
	printf("\n");
	return 0;
}