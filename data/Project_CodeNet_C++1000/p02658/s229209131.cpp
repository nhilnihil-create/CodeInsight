#include<stdio.h>

int main()
{
	long long n;
	long long ctr = 1;
	scanf("%lld", &n);
	long long num[n];
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &num[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(num[i] == 0){
			printf("0\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		if(num[i] <= 1000000000000000000/ctr){
			ctr *= num[i];
		}else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", ctr);
}