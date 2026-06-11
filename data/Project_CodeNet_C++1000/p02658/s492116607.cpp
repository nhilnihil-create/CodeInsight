#include <stdio.h>

int main (){
	
	int a; 
	long long int ans = 1;
	scanf ("%d", &a);
	long long arr[a + 10];
	long long int batas = 1e18;
	for (long long int i = 0 ; i < a ; i++){
		scanf ("%lld", &arr[i]);
	}
	
	for (long long int i = 0 ; i < a ; i++){
		if (arr[i] == 0){
			printf ("0\n");
			return 0;
		}
	}
	
	for (long long int i = 0 ; i < a ; i++){
		if (batas/ans < arr[i]){
			printf ("-1\n");
			return 0;
		}
		ans *= arr[i];
	}
	printf ("%lld\n", ans);
	
	
	return 0;
}
