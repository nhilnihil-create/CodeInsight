#include <stdio.h>

int main(){
	long long int x;
	scanf("%lld", &x);
	long long int x1[x];
	long long int x2 = 1;
	long long int max = 1000000000000000000;
	
	for(int a=0;a<x;a++){
		scanf("%lld",&x1[a]);
	}
	
	for(int a1=0;a1<x;a1++){
		if(x1[a1]==0){
			printf("0\n");
			return 0;
		}
		
	}
	
	for(int a2=0;a2<x;a2++){
		if(x1[a2]<=max/x2){
			x2= x2*x1[a2];
		}
		else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld",x2);
	
	
	
	
	
	
	return 0;
}