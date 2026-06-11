#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	int c = a;
	c += a*a;
	c += a*a*a;
	printf("%d",c);
return 0;
}