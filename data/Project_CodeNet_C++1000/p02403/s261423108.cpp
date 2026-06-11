#include<stdio.h>
int main(void)
{
	int H, W, i,n;
	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0)break;
		for (i = 0; i < H; i++)
		{
			for (n = 0; n < W-1; n++)
			{
				printf("#");
			}
			printf("#\n");
		}
		printf("\n");
	}
	return 0;
}