#include <stdio.h>

int main (){
	
	int h, a, z, y;
	scanf ("%d %d", &h, &a);
	z = h%a;
	y = h/a;
	if (z > 0 ){
		printf ("%d\n", y+1);
	}
	else {
		printf ("%d\n", y);
	}
	return 0;
}