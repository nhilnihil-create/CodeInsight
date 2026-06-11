#include <stdio.h>
#include <string.h>

int main()
{
	char a,b,c,d,e,f;
	scanf("%c%c%c%c%c%c", &a, &b, &c, &d, &e, &f);
	
	if(c==d && e==f)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}