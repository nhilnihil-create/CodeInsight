#include<stdio.h>
int main(){
	int HP,damage;
	scanf("%d %d", &HP, &damage);
	if((HP%damage==0)&&(HP>damage)) printf("%d\n", HP/damage);
	else if((HP%damage!=0)&&(HP>damage)) printf("%d\n", HP/damage+1);
	else if(damage<=damage) printf("1\n");
	return 0;
}