#include <stdio.h>

int main () {
	int n, multi;
	int x = 1;
	scanf("%d %d", &n, &multi);
	long long int arr[n] = {};
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = multi - 1; i < n; i++) {
		if(x == 1) {
			x = 0;
			continue;
		}
		if(arr[i] > arr[i - multi]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}