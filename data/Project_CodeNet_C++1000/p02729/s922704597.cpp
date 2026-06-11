#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int counter = 0;
	
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			counter++;
		}
	}
	
	for(int i = 0; i<m; i++){
		for(int j = i+1; j<m; j++){
			counter++;
		}
	}
	
	printf("%d\n", counter);
	
	return 0;
}