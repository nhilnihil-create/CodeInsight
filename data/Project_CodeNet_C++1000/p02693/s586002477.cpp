#include <stdio.h>
 
int main ()
{
	int a,min,max,jawab;	
	scanf("%d", &a);
	scanf("%d %d", &min, &max);
		for (min;min<=max;min++)
		{
			if(min%a==0)
			{
			jawab++;
			}	
		}
	if(jawab!=0)
	{
		printf("OK");
	}
	else
	{
		printf("NG");
	}
	return 0;
}