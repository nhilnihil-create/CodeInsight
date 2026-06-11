#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	int a,b;
	double c;
	scanf("%d",&a);
	scanf("%d",&b);
	
	c = (double)a/b;
	
	printf("%d %d %f",a/b,a%b,c);
	
return 0;}