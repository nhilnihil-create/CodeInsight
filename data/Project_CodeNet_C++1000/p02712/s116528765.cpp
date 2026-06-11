#include <stdio.h>
int main (){
	long long int c;
	scanf ("%lld", &c);
	long long int sum = 0;
	for (int i = 1; i <= c; i++){
		if (i % 3 == 0 && i % 5 == 0){
			continue;
		}else if (i % 3 == 0){  
		    continue;
		}else if (i % 5 == 0){
			continue;
		}else {
			sum += i;
		}
	}
	printf ("%lld", sum);
	return 0;
}