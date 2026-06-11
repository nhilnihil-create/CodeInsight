#include<stdio.h>

int main(void)
{
	int ok[28], i, m;
	for(i=0; i<28; i++)
	{
		scanf("%d", &ok[i]);
	}
	for(m=1; m<=30; m++)
	{
		for(i=0; i<28; i++)
		{
			if(m==ok[i])
			{
				break;
			}
			else if(m!=ok[i]&&i==27)
			{
				printf("%d\n", m);
			}
		}
	}
	
	return 0;
}
