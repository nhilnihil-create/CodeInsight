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
	
	if(n < k){
		if( n < abss(n - k))
			printf("%lld",n);
		else
			printf("%lld",abss(n-k));
	}else{
		if(n%k == 0)
			printf("0");
		else
			printf("%lld",(((n/k)+1)*k)-n);
	}
	
	return 0;
}