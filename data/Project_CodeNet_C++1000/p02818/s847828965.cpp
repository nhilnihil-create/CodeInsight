#include<stdio.h>
int main()
{
	long long int a,b,k;
	scanf("%lld %lld %lld",&a,&b,&k);
	if(a>k){
		a=a-k;
	}
	else{
		k=k-a;
		a=0;
		if(k>b){
			b=0;
		}
		else{
			b=b-k;
		}
	}
	printf("%lld %lld\n",a,b);
	return 0;
}