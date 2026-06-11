#include <stdio.h>

int main (){
	int health, attack;
	
	scanf ("%d %d", &health, &attack);
	printf ("%d\n", ((health - 1) / attack) + 1);
	return 0;
}