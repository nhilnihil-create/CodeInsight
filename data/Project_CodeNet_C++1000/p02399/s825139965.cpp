#include<stdio.h>
main(){
	int a,b;
	int d1,mo;
	double d2;

	scanf("%d %d",&a,&b);
	d1 = a / b;
	mo = a % b;
	d2 = (double)a / (double)b;

	printf("%d %d %f\n",d1,mo,d2);
	return 0;
}