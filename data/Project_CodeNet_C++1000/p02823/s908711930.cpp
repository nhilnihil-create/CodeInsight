#include<stdio.h>
#include<iostream>
using namespace std;
main(){
	long long n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
	if((b-a)&1)printf("%lld\n",min((unsigned long long)((n<<1)-a-b+1),(unsigned long long)(a+b-1))>>1);
	else printf("%lld\n",b-a>>1);
	return 0;
}