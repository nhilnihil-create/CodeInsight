
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int i, j, x, y;
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (1)
	{
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		for(i = 1;i<=x;i++)
		{
			for (j=1;j<=y;j++)
			{
				printf("#");
			}
			printf("\n");
			j = 0;
		}
		printf("\n");
	}

	return 0;
}