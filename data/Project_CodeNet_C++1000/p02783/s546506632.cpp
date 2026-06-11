#include <stdio.h>
int main() {
	int hp,dmg;
	scanf("%d %d",&hp,&dmg);
	hp % dmg == 0 ? printf("%d",hp/dmg) : printf("%d",(hp/dmg)+1);
	return 0;
}