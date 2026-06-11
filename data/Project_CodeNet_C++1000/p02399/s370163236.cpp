#include<stdio.h>

int main(void){
	int x,y,syou,amari;
	scanf("%d%d",&x,&y);
	printf("%d %d %.8lf\n",x / y,x % y,(double)x / y);

	return 0;
}