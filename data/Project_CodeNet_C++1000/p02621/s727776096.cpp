#include <stdio.h>

int main (){
	int a, a2, a3;
	
	scanf ("%d", &a);
	a = a ;
	a2 = a*a;
	a3 = a2*a;
	printf ("%d", a + a2 + a3);
	return 0;
}