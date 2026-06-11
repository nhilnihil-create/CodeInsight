#include <stdio.h>

int main (){
	int a;
	int b, c, d;
	scanf ("%d", &a);
	
	b = a * a;
	c = a * a * a;
	d = a + b + c;
	
	printf ("%d\n", d);

	return 0;
}