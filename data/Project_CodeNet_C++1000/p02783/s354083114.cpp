#include<stdio.h>
int main() {
    int health,attack;
    scanf("%d %d", &health, &attack);
    (health % attack == 0) ? printf("%d\n",health/attack):printf("%d\n",(health/attack)+1);
 
 
	return 0;
}