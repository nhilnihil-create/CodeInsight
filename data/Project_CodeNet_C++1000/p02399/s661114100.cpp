#include<stdio.h> //gomi
int main(void)
{
	long long int a,b;
	double a1,b1,d,r,f;
	scanf("%lld %lld",&a,&b);
		a1=a;
		b1=b;
		f=a1/b1;
	printf("%lld %lld %f\n",a/b,a%b,f);
	return 0;
}