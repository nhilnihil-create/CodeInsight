#include <stdio.h>

int main(){
	
	long long int N, sum = 0;
	scanf("%lld", &N);
	
	for(int i=1; i<=N; i++){
		if(i%3 == 0){
		}
		else if(i%5 == 0){
		}
		else if(i%3 == 0 && i%5 == 0){
		}
		else{
			sum+= i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}