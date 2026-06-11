#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
long long n,a,b;
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	if ((b-a)%2==0) return printf("%lld",(b-a)/2),0;
	long long res=min(b-1,n-a); res=min(res,min((a+b)/2,(2*n-a-b+1)/2));
	return printf("%lld",res),0;
}