#include<stdio.h>

int main(){
	int k;
	char word[100];
	scanf("%d", &k);
	scanf("%s", &word);
	
	int len = 0;
	
	for(int i = 0; word[i] != '\0'; i++){
		len++;
	}
	
	if(len <= k){
		printf("%s\n", word);
	}
	else{
		for(int i = 0; i < k; i++){
			printf("%c", word[i]);
		}
		printf("...\n");
	}
	return 0;
}