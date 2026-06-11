#include <stdio.h>

int main()
{
	int number1;
	scanf("%d", &number1);
	int number2;
	scanf("%d", &number2);
	int number3;
	scanf("%d", &number3);
	(number1 + number2 + number3 >= 22) ? puts("bust") : puts("win");
	
	return 0;
}