#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < 10; i++){
		int flag = 0;
		for(int j = 1; j < 10; j++){
			if(i * j == n){
				flag = 1;
			}
		}
		
		if(flag == 1){
			printf("Yes");
			break;
		}
		else if(i == 9 && flag == 0){
			printf("No");
		}
	}
	
	return 0;
}