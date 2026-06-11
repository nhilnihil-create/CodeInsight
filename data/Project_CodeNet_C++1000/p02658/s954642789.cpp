#include <stdio.h>

	int main() {
		long long a, flag = 0;
		long long last = 1;
		
		scanf("%lld", &a);
		long long arr[a] = {};
		
		for(int i = 0; i < a; i++) {
			
			scanf("%lld", &arr[i]);
			
		}
		
		for(int i = 0; i < a; i++) {
			if(arr[i] == 0) {
				printf("0\n");
				
				return 0;
			}
		}

		for(int i = 0; i < a; i++) {
				
			if(arr[i] <= 1000000000000000000/last) {
				last =  last * arr[i];
			}
			
			else {
				
				printf("-1\n");
				return 0;
			}
		
	}
	printf("%lld", last);
	return 0;
}

