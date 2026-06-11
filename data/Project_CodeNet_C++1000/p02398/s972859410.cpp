#include<stdio.h>

int main()
{
	int a, b, c;
	int cnt = 0;
	
    scanf("%d%d%d", &a, &b, &c);

	for (int i = 1; i < c+1; i++)
	{
		if (c%i == 0)
		{
			if (i >= a && i <= b)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	
	return 0;
}