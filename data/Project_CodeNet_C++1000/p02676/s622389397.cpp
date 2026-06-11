#include <stdio.h>
#include <string.h>

int main (){
	int K; 
	char S [101];
	
	scanf ("%d\n", &K);
	scanf ("%s", &S);
	
	int len = strlen (S);
	if	(len <= K){
		printf ("%s", S);
	}
	else {
		for (int i = 0 ; i < K; i++){
			printf ("%c", S[i]);
		}
		puts ("...");
	}
	
	return 0;
}