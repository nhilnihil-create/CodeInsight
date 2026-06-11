#include <stdio.h>

int main() {
	int hp, dmg, atk;
	scanf("%d %d", &hp, &dmg);
	
	atk = (hp%dmg);
	atk == 0 ? atk = hp/dmg : atk = (hp/dmg)+1;
	printf("%d", atk);
	
	return 0;
}