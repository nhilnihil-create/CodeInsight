#include <stdio.h>
int main(void)
{
	int h;
	int w;
	int a;
	int b;

	

	for (;;)
	{
		scanf("%d %d", &h, &w);
		if (w==0 && h==0)
		{
			return 0;
		}
		for (b=0;b<h;b++)
		{
			for (a=0;a<w;a++)
			{
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
		
	}

	return 0;
}