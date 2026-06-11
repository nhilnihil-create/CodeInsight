#include <stdio.h>
 
int main(){
	
	long long int n, sum=0;
	
	
	scanf("%lld", &n);
	
	for (int i=n; i>=1; i--){
		
		if(i%3!=0 && i%5!=0){
			sum=sum+i;
		n--;
		
		}		
	}
	
	printf("%lld", sum);
	
	return 0;
}