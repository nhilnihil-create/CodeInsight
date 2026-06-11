#include <stdio.h>

int main () {
	int test;
	scanf("%d", &test);
	int fizzbuzz;
	long long int jumlah = 0;
	for(int i = 1 ; i<=test ; i++){	
		if(i % 3 == 0 && i % 5 == 0){
			fizzbuzz+=i;
		}else if(i % 3 == 0 || i % 5 == 0 ){
			fizzbuzz+=i; 
		}else{
			jumlah+=i;
		}
	}
	printf("%lld\n", jumlah);
	return 0;
}