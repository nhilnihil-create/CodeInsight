#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i, rank;
	char sym;
	int card[4][14] = {0};
	for (i = 1; i <= n; i++)
	{
		scanf(" %c %d\n", &sym, &rank);
		switch (sym)
		{
		case 'S':
			card[0][rank-1] = -1;
			break;
		case 'H':
			card[1][rank-1] = -1;
			break;
		case 'C':
			card[2][rank-1] = -1;
			break;
		case 'D':
			card[3][rank-1] = -1;
		}
	}
	int j, k;
	for (j = 0; j <= 3; j++)
	{
		switch (j)
		{
		case 0:
			for (k = 0; k <= 12; k++)
			{
				if (card[0][k] != -1) printf("S %d\n", k + 1);
			}
			break;
		case 1:
			for (k = 0; k <= 12; k++)
			{
				if (card[1][k] != -1) printf("H %d\n", k + 1);
			}
			break;
		case 2:
			for (k = 0; k <= 12; k++)
			{
				if (card[2][k] != -1) printf("C %d\n", k + 1);
			}
			break;
		case 3:
			for (k = 0; k <= 12; k++)
			{
				if (card[3][k] != -1) printf("D %d\n", k + 1);
			}
		}
	}
	return 0;

}