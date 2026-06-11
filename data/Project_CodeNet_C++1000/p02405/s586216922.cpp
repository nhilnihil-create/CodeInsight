#include<stdio.h>

int main()
{
	int H, W;
	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0) break;
		int i, j;
		for (i = 1; i <= H; i++)
		{
			if (i % 2 == 1)
			{
				for (j = 1; j <= W - 1; j++)
				{
					if (j % 2 == 1)printf("#");
					if (j % 2 == 0)printf(".");
				}
				if (j % 2 == 1)printf("#\n");
				if (j % 2 == 0)printf(".\n");
			}
			else
			{
				for (j = 1; j <= W - 1; j++)
				{
					if (j % 2 == 0)printf("#");
					if (j % 2 == 1)printf(".");
				}
				if (j % 2 == 0)printf("#\n");
				if (j % 2 == 1)printf(".\n");
			}

		}
		printf("\n");
	}

	return 0;
}