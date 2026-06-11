#include<stdio.h>


int main(){
	int x;
	scanf("%d",&x);
	long long int sum = 0;
	for(int i = 1;i<=x;i++){
		if ( i % 3 !=0 && i % 5 !=0 && i % 15 !=0) sum+=i;
		
	}
	printf("%lld\n",sum);
	
	
	
	
	return 0;
}