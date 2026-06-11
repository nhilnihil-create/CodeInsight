#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dice{
	int num[6];
};

int main()
{
	int n;
	dice one;
	for (n = 0; n < 6; n++)
	{
		scanf("%d", &one.num[n]);
	}
	int turn, tmp, i = 2;
	scanf("%d", &turn);
	int top, front;
	for (n = 0; n < turn; n++)
	{
		scanf("%d %d", &top, &front);
		while (1)
		{
			if (one.num[0] == top)break;
			tmp = one.num[0];
			one.num[0] = one.num[1];
			one.num[1] = one.num[5];
			one.num[5] = one.num[4];
			one.num[4] = tmp;
			if (one.num[0] == top)break;
			tmp = one.num[0];
			one.num[0] = one.num[1];
			one.num[1] = one.num[5];
			one.num[5] = one.num[4];
			one.num[4] = tmp;
			if (one.num[0] == top)break;
			tmp = one.num[0];
			one.num[0] = one.num[3];
			one.num[3] = one.num[5];
			one.num[5] = one.num[2];
			one.num[2] = tmp;
			if (one.num[0] == top)break;
			tmp = one.num[0];
			one.num[0] = one.num[3];
			one.num[3] = one.num[5];
			one.num[5] = one.num[2];
			one.num[2] = tmp;
		}
		while (one.num[1] != front)
		{
			tmp = one.num[1];
			one.num[1] = one.num[2];
			one.num[2] = one.num[4];
			one.num[4] = one.num[3];
			one.num[3] = tmp;
		}
		printf("%d\n", one.num[2]);
	}
}