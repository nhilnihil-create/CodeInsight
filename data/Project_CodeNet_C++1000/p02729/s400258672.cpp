#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d", (a*a-a)/2+(b*b-b)/2);
	
	return 0;
}