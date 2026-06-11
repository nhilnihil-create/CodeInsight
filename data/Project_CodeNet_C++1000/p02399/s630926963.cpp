#include<stdio.h>
int main(){
	int a,b,d=0,r=0;
	double f=0.0;
        scanf("%d%d",&a,&b);
	d=a/b;
	r=a%b;
	f=(double)a/b;
	printf("%d %d %f\n",d,r,f);
	return 0;
}