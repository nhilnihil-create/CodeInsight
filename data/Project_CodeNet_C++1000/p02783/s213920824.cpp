#include <stdio.h>
#include <string.h>

int main () {
	
	int a, h ;
	scanf ("%d %d", &h, &a);
	
	h%a > 0 ? printf ("%d", h/a+1) : printf ("%d", h/a);
	
	
	return 0;
}