#include<stdio.h>
#include<cctype>
#include<string.h>


int main(void){

	char s[1200];
	int i;

	gets(s);

	for(i=0;i<strlen(s);i++){
		if(s[i] <= 'z' && s[i] >= 'a')
			printf("%c",toupper(s[i]));
		else
			printf("%c",tolower(s[i]));
	}
	puts("");

	return 0;

}