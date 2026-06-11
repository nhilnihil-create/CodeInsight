#include<stdio.h>

int main()
{
	int num, i, remind, save;
	scanf("%d", &num);
	
	i = 1; 
	while(num!=0)
	{
		remind = num % 10;
		num = num / 10;
		if(remind == 7)
		 {
		 	save = 1;
		 	break;
		 }
		 else {
		 	save = 2;
		 }
	}
	if(save == 1)
		printf("Yes\n");
	else 
		printf("No\n");
}