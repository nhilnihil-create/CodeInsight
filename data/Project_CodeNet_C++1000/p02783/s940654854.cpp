#include<stdio.h>
int main(){
	int health;
	int attack;
	int total;
	scanf("%d %d", &health, &attack);
	health%attack > 0 ? printf("%d", health/attack + 1) : printf("%d", health/attack);
	return 0;
}