#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%s",a);
	if(strlen(a)%2)
	printf("No");
	else
	{
		for(int i=0;a[i]!='\0';i+=2)
		{
			if(a[i]=='h'&&a[i+1]=='i')
			;
			else
			{
				printf("No");
				return 0;
			}
		}
		printf("Yes");
	}
	
	return 0;
}