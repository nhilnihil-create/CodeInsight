#include <stdio.h>

int main(){
	
	long long int n;
	long long int total=0;
	scanf("%lld", &n);
	
	for (int i=1;i<=n;i++){
		if( i%3==0 && i%5==0){
		}
		else if(i%3==0){
		}
		else if(i%5==0){
		}
		else{
			total+=i;
		}
	}
	
	printf("%lld", total);
	
	return 0;
}