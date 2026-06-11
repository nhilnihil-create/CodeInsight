#include <stdio.h>

int main (){
	int H, A, hasil;
	
	scanf ("%d %d", &H,&A);
	
	int hasil1= H/A;
	int hasil2 = H/A+1;
	
	H%A==0 ? printf ("%d",hasil1) : printf ("%d",hasil2);
	
	return 0;
}