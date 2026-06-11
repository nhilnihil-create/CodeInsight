#include<stdio.h>
int main(){
	int A;
	int B;
	scanf("%d",&A);
	scanf("%d",&B);

	if(A==1&&B==2){
		printf("%d\n",A+B);
	}
	else if(A==2&&B==1){
		printf("%d\n",A+B);	
	}
	else if(A==3&&B==1){
		printf("%d\n",A-B);
	}
	else if(A==2&&B==3){
		printf("%d\n",B-A);
	}
	else if(A==3&&B==2){
		printf("%d\n",A-B);
	}
	else if(A==1&&B==3){
		printf("%d\n",B-A);
	}

	
	return 0;
}