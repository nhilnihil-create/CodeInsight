#include <stdio.h>

int main(){
	int amount, first, second;
	int mark = 0;
	
	scanf("%d", &amount);
	scanf("%d %d", &first, &second);
	
	for(int i = first; i <= second; i++){
		if(i % amount == 0){
			mark = 1;
		}
	}
	
	if(mark == 1){
		printf("OK\n");
	}else{
		printf("NG\n");
	}
	return 0;
}