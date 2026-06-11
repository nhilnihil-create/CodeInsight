#include<stdio.h>
int main()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	if(a<10)
	printf("%d\n", b+(100*(10-a)));
	else
	printf("%d\n", b);
	
	return 0;
}