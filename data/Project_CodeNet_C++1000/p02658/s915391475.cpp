#include <stdio.h>
int main(){
  long long int t;
  scanf("%lld", &t);
  long long input[t];
  
  for(long long int i = 0; i < t; i++){
  	scanf("%lld", &input[i]);
	}
	for(long long int i = 0; i < t; i++){
		if(input[i] == 0){
			printf("0\n");
			return 0;
		}
	}
	long long int sum = 1;
	for(int i = 0; i < t; i++){
		if(input[i] <= 1000000000000000000/sum){
			sum *= input[i];
		}else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", sum);
	
  return 0;
}