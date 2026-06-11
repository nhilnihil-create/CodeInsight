#include<stdio.h>

int main(){

	int n,x=0;
	scanf("%d",&n);
	
	if(n>=1 && n<=81){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
			if(i*j == n && i>=j){
				printf("Yes");
				x++;
				break;
			}
		}
		if(x > 0){
			break;
		}
		}
		if(x == 0){
			printf("No");
		}
	}
	else {
		printf("No");
	}

	return 0;
}