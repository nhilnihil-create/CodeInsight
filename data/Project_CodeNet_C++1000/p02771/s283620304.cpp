#include <stdio.h>
int main(){
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if(A==B&&B==C&&C==A){
		printf("No\n");	 
	}
	else if(A!=B&&A!=C&&B!=C)
		printf("No\n");
	 else if(A==C&&A!=B&&C!=B)
		printf("Yes\n");
	 else if(A==B&&A!=C&&B!=C)
		printf("Yes");
	 else if(B==C&&B!=A&&C!=A)
		printf("Yes");
	
	
	return 0; 
}