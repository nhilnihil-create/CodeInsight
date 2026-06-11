#include <stdio.h>
int main(){
	long long int a; 
	long long int number[100000];
	scanf("%lld", &a);
	for(long long int i=0; i<a; i++){
		scanf("%lld", &number[i]);
	}
	for(long long int i = 0; i<a; i++){
		if(number[i]==0){
			printf("0\n");
			return(0);
			
		}
	}
	long long int ans = 1;
	for(int i = 0; i<a; i++){
		if(number[i]<= (1000000000000000000/ans) ){
			ans=ans*number[i];
		
		}else {
			printf("-1\n");
			return(0);
		}
	} printf("%lld\n", ans);
	return 0;
}
