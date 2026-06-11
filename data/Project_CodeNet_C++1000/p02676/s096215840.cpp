#include <stdio.h>
#include <string.h>

int main() {
	
	char s[101];
	int k;
	scanf("%d",&k);
	getchar();
	scanf("%[^\n]", &s);
	
	if (strlen(s) > k ){
		for(int i = 0; i < k; i++){
			printf("%c", s[i]);
		}
		printf("...\n");
	}else{
		for(int i = 0; i < strlen(s); i++){
			printf("%c", s[i]);
		}
	}

	
	
	
	return 0;
}
