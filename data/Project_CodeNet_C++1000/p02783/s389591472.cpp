#include <stdio.h>
int main()
{
	int health,attack,swing,left;
	
	scanf("%i %i",&health,&attack);
	
	swing = health/attack;
	left = health%attack;
	
	left > 0 ? printf("%i",swing + 1) : printf("%i",swing);
	
	return 0;
}