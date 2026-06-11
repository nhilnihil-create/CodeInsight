#include<stdio.h>

int main()
{
	char str[100];
	scanf("%s", str);
	
	switch (str[1])
	{
		case 'B': printf("ARC\n");
		break;
		case 'R': printf("ABC\n");
		break;
	}
	
	return 0;
}