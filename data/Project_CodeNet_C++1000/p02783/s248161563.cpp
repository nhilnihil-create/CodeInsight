#include <stdio.h>

int main (){
	int H, A, hasil;
	
	scanf ("%d %d", &H,&A);
	hasil= ((H-1)/A+1);
	
	printf ("%d", hasil);
	
	return 0;
}