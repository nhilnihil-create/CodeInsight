#include<stdio.h>

int main(){
	
	int h1,m1,h2,m2,k;
	scanf("%d %d %d %d %d",&h1,&m1,&h2,&m2,&k);
	int minute1,minute2;
	
	minute1 = h1*60 + m1;
	minute2 = h2*60 + m2;
	//printf("Minute 1 : %d\n",minute1);
	//printf("Minute 2 : %d\n",minute2);
	
	printf("%d",(minute2-minute1)-k);
	
	
	
	
	return 0;
}