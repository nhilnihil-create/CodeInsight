#include <stdio.h>
int main ()
{
	int A1=1-13,A2=1-13,A3=1-13;
	scanf("%d", &A1);
	scanf("%d", &A2);
	scanf("%d", &A3);
	
	if(A1+A2+A3<22){
		printf("win");
	}else if(A1+A2+A3>=22){
		printf("bust");
	}
	return 0;
	
}