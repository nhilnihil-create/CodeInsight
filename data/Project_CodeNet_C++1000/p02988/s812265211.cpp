#include <stdio.h>

int main () {
	
	int count = 0, n, x[100];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	
	for(int j = 1; j < n - 1; j++){
		if(x[j] > x[j-1] && x[j] < x[j+1]){
			count++;
		}
		else if(x[j] < x[j-1] && x[j] > x[j+1]){
			count++;
		}
	}
	
	printf("%d", count);
	
	
	
	
	
	
	
	
	
	
	return 0;
}