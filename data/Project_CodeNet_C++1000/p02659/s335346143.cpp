#include<stdio.h>
#include<math.h>
int main()
{
	long long int a,b,ans;
    double s;
	scanf("%lld %lf",&a,&s);
	b=round(s*100);
	ans=a*b/100;
	printf("%lld",ans);
}