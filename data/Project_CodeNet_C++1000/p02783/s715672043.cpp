#include <stdio.h>


int main ()
{
int H,A,J;

scanf("%d %d", &H, &A);
J=H/A;

if (H%A==0){
	printf("%d", J);
}
else if(H%A!=0){
	J++;
	printf("%d", J);
}



	return 0;
	}