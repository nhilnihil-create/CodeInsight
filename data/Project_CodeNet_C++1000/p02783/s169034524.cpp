#include <stdio.h>

int main (){
	int health;
	int damage;
	int valueHit = 0; 
	
	scanf("%d %d", &health, &damage);
	
	health%damage == 0?printf("%d", health/damage) : printf("%d", health/damage +1);
	
	
	return 0;
}