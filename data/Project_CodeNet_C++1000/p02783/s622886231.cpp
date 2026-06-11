#include<stdio.h>

int main()
{
	int H , A , R , T;
	scanf("%d %d", &H, &A);
	R = H%A;
	T = (H-R)/A;
	R != 0 ? printf("%d", T + 1 ) : printf("%d", T );

	return 0;
}