#include <stdio.h>

int main (){
	
	int n,z;
	scanf ("%d", &n);
	( n%2 != 0 ) ? printf ("%d\n", n/2 +1) : printf ("%d\n", n/2);
	return 0;
}