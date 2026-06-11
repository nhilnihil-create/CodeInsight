#include <stdio.h>

int main() {
	long long int N;
	long long int sum = 0;
	scanf("%lld", &N);
	
	for(int i = 0; i <= N; i++){
		if(i % 3 == 0 || i % 5 == 0){
			continue;
		}else{
			sum += i;
		}
	}
	
	printf("%lld", sum);
	
	return 0;
}