#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	int poin = 0;
	
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			if( i * j == n){
				poin = 1;
			}
		}
	}
	
	if(poin == 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}