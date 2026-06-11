#include <stdio.h>
#include <string.h>
int main(){
	char words[105];
	int k;
	int word;
	scanf("%d" ,&k);
	scanf("%s" ,words);
	word = strlen(words);
	if (word <= k){
		printf("%s" ,words);
	}
	else if(word > k){
		words[k] = '\0';
		printf("%s..." ,words);
	}
	return 0;
}