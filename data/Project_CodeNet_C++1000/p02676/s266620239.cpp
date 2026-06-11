#include <stdio.h>
#include <string.h>

int main(){
	char str[101];
	int k;
	
	scanf("%d\n%s",&k, str);
	int len = strlen(str);
	
	if(len<=k){
		printf("%s\n", str);
	}
	else{
		for(int i=0;i <k; i++){
			printf("%c",str[i]);
		}
		printf("...\n");
	}
		
	return 0;}