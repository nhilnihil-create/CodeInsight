#include <stdio.h>
#include <math.h>
int main(){
	int a,b,d,r;
	double f;
	scanf("%d %d",&a,&b);
	d=a/b;
	f=(double)a/b;
	r=a-b*d;
	printf("%d %d %f",d,r,f);
	return 0;
}