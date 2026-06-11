#include <stdio.h>

int main(){
	long long int n;
	long long int sum = 0;
	scanf("%lld" ,&n);
	for(int i = 1; i <= n; i++){
	if(i % 3 == 0 && i % 5 == 0){
		continue;
	}
	else if(i % 3 == 0){
		continue;
	}
	else if(i % 5 == 0){
		continue;
	}
	else{
		sum = sum + i;
	}
		}
	printf("%lld\n" ,sum);
	return 0;
}