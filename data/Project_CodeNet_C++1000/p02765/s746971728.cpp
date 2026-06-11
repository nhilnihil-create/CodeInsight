#include <stdio.h>

int main(){
	int a,b,x;
	
	scanf("%d %d", &a, &b);
	
	x = 100*(10-a);
	
	if (a>=10){
		printf("%d", b);
	}
		else 
		printf ("%d", b + x);
	
	return 0;
}