#include <stdio.h>

int main(){
	
	int n;
	scanf ("%d", &n);
	long long int result = 0;
	for (int i = 0; i <= n; i++){
		int check = 0;
		if (i % 3 == 0 || i % 5 == 0){
			check = 1;
		}
		else if(check == 0){
			result += i;
		}
	}
	printf ("%lld\n", result);
	
	return 0;
	
}