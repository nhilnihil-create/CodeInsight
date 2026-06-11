#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char str[102];
	scanf("%s",&str);
	int len=strlen(str);
	if(len>n)
	{
		str[n]='.';
		str[n+1]='.';
		str[n+2]='.';
		str[n+3]='\0';
	}
	printf("%s",str);
	return 0;
}