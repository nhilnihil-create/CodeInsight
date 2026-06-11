#include<stdio.h>

int main(){
	long long n,k;
	scanf("%lld %lld",&n,&k);
	long long sum = 0;
	long long  i;
	for(i = k;i <= n+1;i++){
		sum += (n - i + 1)*i + 1;
	}
	
	printf("%lld",sum%1000000007);
} 