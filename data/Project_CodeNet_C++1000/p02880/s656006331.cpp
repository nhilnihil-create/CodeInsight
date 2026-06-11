#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int flag = 0;

	for (int i=1; i<10; i++){
		for (int j=i; j<10; j++){
			if (i*j == n){
				flag = 1;
				break;
			}
		}
		if (flag){
			break;
		}
	}

	if (flag){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}
