#include <stdio.h>

int main()
{
	char a[6];
	scanf("%s", &a);
	
	if(a[2] == a[3] && a[4] == a[5])
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}