#include <stdio.h>
#include <string.h>
 
int main(){
	
	char S[255];
	int k;
	scanf("%d", &k);
	scanf("%s", &S);
	for(int i = 0; i < strlen(S); i++){
	}
	if( k > 255 ||  k < 1){
		return 0;
	}
	if (k >= strlen(S)){
		printf("%s", S);
	}else if (k < strlen(S)){
		for( int i =0; i < k; i++){
			printf("%c", S[i]);
		}
		printf("...");
	}
	return 0;
}