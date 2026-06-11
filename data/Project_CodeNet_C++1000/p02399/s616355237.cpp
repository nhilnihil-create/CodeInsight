#include<stdio.h>
int main(void){
	double f=0.0;
	int  a = 0, b = 0,d = 0, r = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	d = a / b;
	r = a%b;
	f = double(a) / double(b);
	printf("%d %d %.5f\n", d, r, f);
	return 0;
}