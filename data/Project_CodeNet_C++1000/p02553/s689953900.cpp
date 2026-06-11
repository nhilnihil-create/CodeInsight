#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long x1=a*c;
	long long x2=a*d;
	long long x3=b*c;
	long long x4=b*d;
	printf("%lld",max(x1,max(x2,max(x3,x4))));
	return 0;
}