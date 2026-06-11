#include <stdio.h>
int main(){
	int health;
	int attack;
	int turn = 0;
	scanf("%d %d", &health, &attack);
	while(health > 0){
		health = health - attack;
		turn = turn + 1;} 
	printf("%d", turn);
	return 0;
}