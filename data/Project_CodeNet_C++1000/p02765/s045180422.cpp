#include <stdio.h>
int main (){
	
	int n,r,z;
	scanf ("%d %d", &n, &r);
	z = 100 * (10 - n);
	if (n < 10){
		printf ("%d\n", r + z);
	}
	else if (n >= 10){
		printf ("%d\n", r);
	}

	
	return 0;
}