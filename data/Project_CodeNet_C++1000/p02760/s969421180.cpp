#include <stdio.h>
int main() {
	int box[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d",&box[i][j]);
		}
	}
	int tc;
	scanf("%d",&tc);
	int bingo[10];
	for (int i = 0; i < tc; i++)
	{
		scanf("%d",&bingo[i]);	
	}
	int ctr[3][3] = {0};
	for (int i = 0; i < tc; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (bingo[i] == box[j][k])
				{
					ctr[j][k]++;
				}
			}	
		}
	}
	if (ctr[0][0] > 0 && ctr[0][1] > 0 && ctr[0][2])
	{
		printf("Yes\n");
	}
	else if (ctr[1][0] > 0 && ctr[1][1] > 0 && ctr[1][2])
	{
		printf("Yes\n");
	}
	else if (ctr[2][0] > 0 && ctr[2][1] > 0 && ctr[2][2])
	{
		printf("Yes\n");
	}
	else if (ctr[0][0] > 0 && ctr[1][0] > 0 && ctr[2][0])
	{
		printf("Yes\n");
	}
	else if (ctr[0][1] > 0 && ctr[1][1] > 0 && ctr[2][1])
	{
		printf("Yes\n");
	}
	else if (ctr[0][2] > 0 && ctr[1][2] > 0 && ctr[2][2])
	{
		printf("Yes\n");
	}
	else if (ctr[0][0] > 0 && ctr[1][1] > 0 && ctr[2][2])
	{
		printf("Yes\n");
	}
	else if (ctr[0][2] > 0 && ctr[1][1] > 0 && ctr[2][0])
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}