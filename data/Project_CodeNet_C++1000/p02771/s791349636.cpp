#include<stdio.h>
int main(){
	int A;
	int B;
	int C;
	scanf ("%d %d %d",&A,&B,&C);
	
	
	if(A== B &&A!=C&&B!=C){
		printf("Yes");
	}
	else	if(B==C &&B!=A&&C!=A){
	
		printf("Yes");
	}
	else	if(A== C &&A!=B&&C!=B){
		printf("Yes");
	}
		else{
			printf("No");
	}
	
	
	
	return 0;
}