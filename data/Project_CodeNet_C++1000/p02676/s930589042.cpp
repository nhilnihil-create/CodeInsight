#include<stdio.h>
#include<string.h>

int main(){
	int k;
	char word[101];
	
	scanf("%d", &k);
	scanf("%s", &word);
	int len = strlen(word);
	
	if (len <= k){
		printf("%s", &word);
	}
	else {
		word[k] = '\0';
		printf("%s...", word);
	}
	return 0;
}