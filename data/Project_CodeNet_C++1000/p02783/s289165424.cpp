#include <stdio.h>

int main(){
	
	int a, b, c;
	
	scanf("%d %d", &a, &b);
	
	c= (a/b);
	a%b > 0 ? printf("%d", c+1) : printf ("%d", c);
	
return 0;	
}