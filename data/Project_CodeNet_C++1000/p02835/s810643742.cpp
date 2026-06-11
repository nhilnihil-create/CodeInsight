#include <stdio.h>

int main()
{
	int A1, A2, A3, Ai;
	
	scanf("%d %d %d", &A1, &A2, &A3);
	Ai = A1 + A2 + A3;
	
	if (Ai>=22){
		printf("bust\n");
	}
	else 
		printf("win\n");
	return 0;
}
