#include<stdio.h>

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
    if(A == 1){
    	if(B == 2){
    		printf("%d",3);
		}
		else{
			printf("%d",2);
		}
	}
	else if(A == 2){
		if(B == 1){
			printf("%d",3);
		}
		else{
			printf("%d",1);
		}
	}
	else if(A == 3){
		if(B == 2){
			printf("%d",1);
		}
		else{
			printf("%d",2);
		}
	}
	return 0;
}