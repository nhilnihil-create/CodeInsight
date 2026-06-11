#include<stdio.h>
int main(void)

{
	int H, W, i, a;

	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0)
		{
			break;
		}
		for (i = 0; i < H; i++)
		{
			if (i == 0 || i == H - 1)
			{
				for (a = 0; a < W; a++)
				{
					printf("#");
				}printf("\n");
			}
			else
			{
				for (a = 0; a < W; a++)
				{
					if (a == 0 || a == W - 1)
					{
						printf("#");
					}

					else
					{
						printf(".");
					}
				}printf("\n");
			}
		}
			printf("\n");

	}

		return 0;
}
