#include<stdio.h>
int main()
{
	int A;
	scanf("%d", &A);
	int sheet = (A % 2 == 0) ? (A/2) : (A/2) + 1;
	printf("%d\n", sheet);
	return 0;
}