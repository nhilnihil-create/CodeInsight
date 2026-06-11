#include<stdio.h>

#include<stdio.h>
int main(void)
{
	int H, W, i, n;
	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0)break;
		for (i = 0; i < H; i++)
		{
			for (n = 0; n < W; n++)
			{
				if (i == 0 || i == H - 1 || n == 0 || n == W - 1)
				{
					printf("#");
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}