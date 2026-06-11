#include <stdio.h>
int main()
{
	
	int a;
	scanf("%d", &a);
	
	if(a%2==0) {
		printf("%d",a/2);
	}
	else if(a%2 !=0) {
		printf("%d",(a/2)+1);
	}
	

	return 0;
}