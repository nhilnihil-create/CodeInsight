#include <stdio.h>
int main(){
	int numA, numB, numC;
	scanf("%d %d %d", &numA, &numB, &numC);
		if(numA == numB && numB == numC && numA == numC){printf("No");}
		else if(numA != numB && numB != numC && numA != numC){printf("No");}
		else if(numA == numB && numB != numC){printf("Yes");}
		else if(numB == numC && numB != numA){printf("Yes");}
		else if(numA == numC && numA != numB){printf("Yes");}
	return 0;}