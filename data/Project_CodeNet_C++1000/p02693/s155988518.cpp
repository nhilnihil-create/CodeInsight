#include <stdio.h>

int main ()
{
	int mo,min,max,ans;	
	scanf("%d", &mo);
	scanf("%d %d", &min, &max);
		for (min;min<=max;min++)
		{
			if(min%mo==0)
			{
			ans++;
			}	
		}
	if(ans!=0)
	{
		printf("OK");
	}
	else
	{
		printf("NG");
	}
	
	
	return 0;
}