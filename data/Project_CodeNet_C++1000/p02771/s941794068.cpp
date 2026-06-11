#include<stdio.h>
int main (){
	int A,B,C;
		scanf("%d",&A);
		scanf("%d",&B);
		scanf("%d",&C);	
		
	if(A == B && B == C && C == A){
		
		printf("No\n");
	}
	else if (A == B || B == C || C == A){
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	
return 0;
}
