#include <stdio.h>
int main(){
	int hp, atk;
	scanf("%d %d", &hp, &atk);
	if(hp%atk != 0){
		printf("%d", hp/atk+1);
	} else {
		printf("%d", hp/atk);
	}
	return 0;
}