#include <stdio.h>
#include <string.h>

int main(){
	int k,i;
	scanf("%d", &k);
	getchar();
	
	char s[100];
	scanf("%[^\n]", s);
	
	int len = strlen(s);
	
	if(len == k || len < k){
		printf("%s", s);
	} else if(len > k){
		for(i=0; i<k; i++){
			printf("%c", s[i]);
		}
		printf("...");
	}
	
	return 0;
}