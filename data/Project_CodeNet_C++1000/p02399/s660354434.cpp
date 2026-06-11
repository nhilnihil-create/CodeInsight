#include<stdio.h>
int main(void){

	int a,b;
	double x;
	scanf("%d%d",&a,&b,&x);
    x=1.0*a/b;
	printf("%d %d %.8lf\n",a/b,a%b,x);
	return 0;
}