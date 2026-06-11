#include<stdio.h>
int main(){
	int h1,h2,m1,m2,k;
	int a,b,c,d;
	
	scanf("%d %d %d %d %d", &h1,&m1,&h2,&m2,&k);
	
	a = (h1*60) +m1;
	b=(h2*60) +m2;
	c = b-a;
	d = c- k;  
	
	printf("%d\n", d);
	return 0;
}