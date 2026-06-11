#include<stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	long long int sum=0;
	for(int i=1; i<=n; i++){
		if(i%3==0 && i%5==0){
			sum+=0;
	
		}
		else if(i%3==0){
			sum+=0;
	
		}
		else if(i%5==0){
			sum+=0;
		
		}
		else{
			sum+=i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}