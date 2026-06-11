#include <stdio.h>
int main(){
	
	char A[1200]={0}, B[1200]={0};
	char C[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char D[] = {"abcdefghijklmnopqrstuvwxyz"};
	
	gets(A);
	
	for(int i = 0; i < 1200; i++){
		for(int j = 0; j < 26; j++){
			if(A[i] == C[j]){
				B[i] = D[j];
				break;
			}
			else if(A[i] == D[j]){
				B[i] = C[j];
				break;
			}
			else{
				//printf("%c = %c \n",B[i], A[j]);
				B[i] = A[i];
			}
		}
	}
	printf("%s\n", B);
  	return 0;
}