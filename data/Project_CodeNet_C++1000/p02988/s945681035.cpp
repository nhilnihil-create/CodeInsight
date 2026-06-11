#include<stdio.h>



int main()
{
	int num[100000],count =0, tc, i, k, l;
	
	scanf("%d", &tc);
	
	for(i =1; i<= tc; i++)
	{
		scanf("%d", &num[i]);	
	} 
	
	for(i = 1; i <= tc-2; i++)
	{
		k = i + 1;
		l = i + 2;
		
		if(num[i] > num[k]  && num[k] > num[l])
		{
			count++;
		}
		else if(num[i] < num[k] && num[k] < num[l])
		{
			count++;
		}
	}
	printf("%d\n", count);
	
	return 0;
	
	
}