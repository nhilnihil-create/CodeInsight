#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int b=a/2;
	(a%2 ==0)?printf("%d", b):printf("%d", b+1);
	printf("\n");
	return 0;
}
