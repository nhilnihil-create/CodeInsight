#include <stdio.h>
#include <string.h>
	int main(){
	int k;
	char s[100];
	
	scanf("%d",&k);
	scanf("%s",&s);
	int len = strlen(s);
	
	if(len <= k){
		printf("%s",s);
	}
	else{
		for( int i=0 ; i<k ; i++){
			printf("%c",s[i]);
		}
		puts("...");
	}
	return 0;
	}