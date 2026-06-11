#include <stdio.h>

int main(void)
{
	int a, b, c; 
	
	scanf("%d",&a);	scanf("%d",&b); scanf("%d",&c);
	
	if(a< b && a< c && b< c)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}