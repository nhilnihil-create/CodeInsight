#include <stdio.h>
int main()
{
	int A1,A2,A3,hasil;
	scanf("%d",&A1);
	getchar();
	scanf("%d",&A2);
	getchar();
	scanf("%d",&A3);
	getchar();
	
	if(A1+A2+A3 >= 22 ){
		
		hasil = A1+A2+A3;
		
			printf("bust\n");
		
	}
	
	else
	{
		hasil = A1+A2+A3;
		
			printf("win\n");
	}
	
	
	
	return 0;
}