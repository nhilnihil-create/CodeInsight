#include <stdio.h>

int main (){
	
	int a,b,c,d;
	scanf ("%d %d %d", &a, &b, &c);
	d = a+b+c;
	if (d >= 22){
		printf ("bust");
	}
	else {
		printf ("win");
	}
	return 0;
}