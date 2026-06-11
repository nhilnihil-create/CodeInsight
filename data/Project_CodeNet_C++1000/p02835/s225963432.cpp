#include<stdio.h>
int main()
{
	int A1;
	int A2;
	int A3;
	int hasil;
	scanf("%d", &A1);
	scanf("%d", &A2);
	scanf("%d", &A3);
	
	if( A1 + A2 + A3 >= 22){
		hasil = A1 + A2 + A3;
		printf("bust\n");
	}
	else {
		hasil = A1 + A2 + A3;
		printf("win\n");
	}
	return 0;
}