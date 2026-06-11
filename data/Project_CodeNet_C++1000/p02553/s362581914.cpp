#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
long long a,b,c,d;

int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long s1=a*c,s2=a*d,s3=b*c,s4=b*d;
	printf("%lld\n",max(s1,max(s2,max(s3,s4))));
	return 0;
}