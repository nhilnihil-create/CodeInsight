#include <stdio.h>
#include <string.h>

int main(){
	
	char S[100];
	int k;
	scanf("%d", &k);
	scanf("%s", &S);
	for(int i = 0; i < strlen(S); i++){
		if( S[i] > 'A' && S[i] < 'Z'){
			return 1;
		}
	}
	if( k > 100 ||  k < 1){
		return 1;
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