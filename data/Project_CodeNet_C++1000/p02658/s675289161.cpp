#include<stdio.h>
int main(){
	long long n;
	long long result = 1;
	
	scanf("%lld", &n);
	long long input[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &input[i]);
	}
	for(int i = 0 ; i < n ; i++){
		if(input[i] == 0){
			printf("0\n");
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(input[i] <= 1000000000000000000/result){
			result *= input[i];
		}else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", result);
	return 0;
}