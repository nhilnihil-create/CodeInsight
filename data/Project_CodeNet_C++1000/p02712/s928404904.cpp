#include <stdio.h>

int main (){
	int a;
	long long int total = 0;
	scanf("%d", &a);
	
	for(int i = 1; i <= a; i++){
		if(i % 5 ==0 && i % 3 ==0 ){
			printf("");
		}
		else if (i % 3 ==0){
			printf("");
		}
		else if (i%5==0){
			printf("");
		}
		else{
			total = total + i;
		}
	}
	
	printf("%lld", total);
	return 0;
}