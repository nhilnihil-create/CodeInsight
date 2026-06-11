#include <stdio.h>
int main(){
int A;
int B;
int C;	
	
scanf("%d",&A);
scanf("%d",&B);
scanf("%d",&C);	

	if(A==C&&A!=B&&B!=C){
	printf("Yes\n");
	}
	else if(A==B&&A!=C&&B!=C){
		printf("Yes\n");
	}
	else if(B==C&&B!=A&&A!=C){
		printf("Yes\n");
	}
	else if(A==B&&A==C&B==C){
		printf("No\n");
	}
	else if(A!=B&&A!=C&B!=C){
		printf("No\n");
	}
	return 0;
}