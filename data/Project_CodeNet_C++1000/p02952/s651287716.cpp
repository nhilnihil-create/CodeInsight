#include<stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	
	
	if(num >= 1 && num <= 9)
		printf("%d\n", num);
	else if(num >= 10 && num <= 99)
		printf("9\n");
	else if(num >= 100 && num <= 999)
		printf("%d\n",  num + 10 - 100);
	
	else if(num >= 1000 && num <= 9999)
		printf("909\n");
	else if(num >= 10000 && num <= 99999)
		printf("%d\n", num + 909 - 10000 + 1);
	else if(num >= 100000)
		printf("90909\n");
		
	return 0;
}