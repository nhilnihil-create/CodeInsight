#include<stdio.h>
int main(void)

{
	int H, W, i,a;

	while (1)
	{
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0)
		{
			break;
		}
		for (i = 0; i < H; i++)
		{
			for (a = 0; a < W; a++)
			{
				printf("#");
			}printf("\n");
		}
		printf("\n");

	}

	return 0;
}
