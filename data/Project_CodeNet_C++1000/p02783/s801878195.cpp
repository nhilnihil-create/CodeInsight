#include <stdio.h>

int main(){
	
	int health, attack, result;
	
	scanf("%d %d", &health, &attack);
	
	result = health % attack <= 0 ? printf("%d", health / attack) : printf("%d", health / attack + 1);

return 0;

}