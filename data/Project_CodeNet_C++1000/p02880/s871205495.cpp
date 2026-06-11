#include <stdio.h>

int main(){
	int inputa,flag=0;
	scanf("%d", &inputa);
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if((i*j)==inputa){
				flag=1;
				break;
			}
		}
	}
	if(flag==1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}