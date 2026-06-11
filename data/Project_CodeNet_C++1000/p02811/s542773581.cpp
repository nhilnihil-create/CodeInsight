#include <stdio.h>

int main (){
	
	int k,x;
	int z = 500;
	scanf ("%d %d", &k, &x);
	if (k*z >= x){
		printf ("Yes\n");
	}
	else if (k*z <= x){
		printf ("No\n");
	}
	return 0;
}