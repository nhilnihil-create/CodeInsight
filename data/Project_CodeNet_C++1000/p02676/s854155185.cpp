#include <stdio.h>
#include <string.h>

int main(){
	int k;
	scanf("%d", &k);
	char s[105];
	scanf("%s", &s);
	
	int length = strlen(s);
	s[k] = '\0';
	if(length > k){
		printf("%s...", s);
	}
	else{
		printf("%s", s);
	}	
	
	return 0;
}