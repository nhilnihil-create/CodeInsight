#include <stdio.h>

int main() {

	long long int n;
	scanf("%lld", &n);
	
	long long sum=0;	
	for(long long int i=1; i<=n; i++){
		if(i%3!=0 && i%5!=0){
			sum+=i;
		}
	}

	printf("%lld\n", sum);
	
    return 0;
}
