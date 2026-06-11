#include <stdio.h>
int main(){
	char c;
	scanf("%c", &c);
	if(c >= 'A' && c <= 'Z'){printf("%c", ++c)
	;}
	else if(c >= 'a' && c <= 'z'){printf("%c", ++c);}
	return 0;
}