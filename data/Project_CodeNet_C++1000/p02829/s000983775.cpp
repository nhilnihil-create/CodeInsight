#include <stdio.h> 
int main() 
{
	int ansA, ansB;
	scanf("%d %d", &ansA, &ansB);
	(ansA != 1 && ansB != 1) ? printf("%d", 1) : 0;
	(ansA != 2 && ansB != 2) ? printf("%d", 2) : 0;
	(ansA != 3 && ansB != 3) ? printf("%d", 3) : 0;
	return 0;
}