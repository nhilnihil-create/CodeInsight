#include <stdio.h>

int main(){
	long long int N = 0, sum = 0;
	scanf("%lld", &N);
	for(int i = 0; i <= N; i++){
		if(i % 3 != 0 && i % 5 != 0){
			sum += i;
		}
	}
	printf("%lld", sum);
	return 0;
}