#include <stdio.h>

int main (){
	char s[100];
	int k;
	int length=0;
	scanf("%d\n", &k);
	scanf("%[^\n]", &s);
	for (int i=0; s[i] != '\0'; i++){
		length++;
	}
	if (length <= k){
		printf("%s", s);
	}
	else if (length > k){
		for (int i=0; i<k; i++){
		printf("%c", s[i]);
		}
		printf("...");
	}
	return 0;
}