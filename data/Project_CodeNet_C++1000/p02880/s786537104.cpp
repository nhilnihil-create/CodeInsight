#include <stdio.h>

int main(){
	int a[9] = {1,2,3,4,5,6,7,8,9};
	int b[9] = {1,2,3,4,5,6,7,8,9};
	int in;
	int y = 0;
	scanf("%d" ,&in);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(a[i] * b[j] == in){
				y++;
			}
		}
	}
	if(y > 0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}