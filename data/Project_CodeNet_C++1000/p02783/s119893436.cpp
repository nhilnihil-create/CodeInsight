#include <stdio.h>

int main ()
{
	int H, A, X;
	
	scanf ("%d %d", &H, &A);
	if (H%A==0){
		printf("%d", H/A);
	}else if (H%A!=0){
		X = (H/A)+1;
		printf("%d", X);
	}
	
	return 0;
}