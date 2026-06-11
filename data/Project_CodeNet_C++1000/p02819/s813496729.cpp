#include<stdio.h>

int isprime(int num)
{
	int i = 2, count=0;
	while(i<num)
	{
		if(num % i == 0)
		    count++;
		
		i++;
	}
	if(count > 1)
	return 0;
	else
		return 1;
}
int main()
{
	int num, i;
	scanf("%d", &num);
	i = num;
	for(i = num; ; i++)
	{
		if(isprime(i))
		break;
	}
	printf("%d\n", i);
}