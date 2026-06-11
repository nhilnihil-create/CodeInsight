#include <stdio.h>
int main(){
	long long int sum = 0;
	int n;
	scanf("%d" , &n);
	for(int i = 0 ; i <= n ; i++){
		if(i%3 == 0 && i%5 == 0){
			continue;
		}
		else if(i%3 == 0){
			continue;
		}
		else if(i%5 == 0){
			continue;
		}
		else{
			sum += i;			
		}	
	}
	printf("%lld\n" , sum);
	
	
	return 0;
}
