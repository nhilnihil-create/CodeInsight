#include <stdio.h>
int main(){
	int darah;
	int damage;
	int finish;
	scanf("%d %d", &darah, &damage);
	finish=darah%damage==0? finish=darah/damage : finish=darah/damage+1;
	printf("%d", finish);
	return 0;
}