#include<stdio.h>

int main()
{
	int H, W;
	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0) break;

		int i, j;
		for (j = 1; j <= H; j++)
		{
			if (j == 1 || j == H)
			{
				for (i = 1; i <= W - 1; i++)
				{
					printf("#");
				}
				printf("#\n");
			}
			else
			{
				printf("#");
				for (i = 2; i <= W - 1; i++)
				{
					printf(".");
				}
				printf("#\n");
			}
			
		}
		printf("\n");
	}

	return 0;
}