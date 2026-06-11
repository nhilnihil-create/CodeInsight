#include <stdio.h>

int main(){
	char word[10];
	scanf("%s", word);
	
	if (word[1] == 'B') puts("ARC");
	else puts ("ABC");
	return 0;
}