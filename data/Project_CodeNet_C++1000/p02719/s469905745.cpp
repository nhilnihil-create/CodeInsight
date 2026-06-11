#include<stdio.h>

long long abss(long long x){
	if(x < 0)
		return x*(-1);
	else
		return x;
}
int main(){
	long long  n,k;
	scanf("%lld %lld",&n,&k);
	
	n%= k;
	if(n > k-n)
		printf("%lld\n",k - n);
	else
		printf("%lld\n",n);
	
	return 0;
}