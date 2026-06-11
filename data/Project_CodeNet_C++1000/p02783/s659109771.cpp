#include<stdio.h>
int main()
{
	int H, A;
	scanf("%d %d", &H, &A);
	(H % A == 0) ? printf("%d\n", H / A) : printf("%d\n", H / A + 1);
	return 0 ;
	
}
