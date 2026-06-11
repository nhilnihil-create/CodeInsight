#include<stdio.h>

int main(){
	long long int n;
	scanf("%lld", &n);
	
	
	long long int total=0;
	
	if(n>=1){
		total=total+1;
	}
	if(n>=2){
		total=total+2;
	}
	if (n>3){
		for (int i = 3; i<=n; i++){
			if(i%3==0|| i%5==0){
				continue;
			}
			total = total + i;
		}
	}
	printf("%lld", total);
	return 0;
}