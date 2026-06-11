#include<stdio.h>

int main (void){
	
	int a,b,d,r;
	double f;
	scanf("%d %d",&a,&b);
	f = (double)a/(double)b;
	
	printf("%d %d %lf",a/b,a%b,f);
return 0;
}