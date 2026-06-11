#include<stdio.h>
main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if ( a == b )
	printf("a == b\n", a, b);
	else if ( a < b )
	printf("a < b\n", a, b);
	else
	printf("a > b\n", a, b);

	
}

