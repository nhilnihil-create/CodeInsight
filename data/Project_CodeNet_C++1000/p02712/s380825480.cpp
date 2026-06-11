#include <stdio.h>

int main (){
	int n;
	scanf ("%d", &n);
	int x;
	long long int sum = 0;
	
	for (x = 1; x <= n; x++){
		if (x % 3 != 0 && x % 5 != 0){
			sum += x;
		}
	}
	printf ("%lld\n", sum);
	
	return 0;
}