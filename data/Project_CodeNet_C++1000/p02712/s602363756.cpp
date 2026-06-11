#include <stdio.h>

int main(){
	long long int input, total = 0;
	
	scanf ("%lld", &input);
	
	for (int i = 1; i <= input; i++){
		if(i % 3 != 0 && i % 5 != 0){
        total += i;
    	}
	}
	
	printf ("%lld", total);
	return 0;
}