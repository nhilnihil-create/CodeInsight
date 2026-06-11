#include <stdio.h>
int main (){
	int n;
	scanf("%d", &n);
	char s[10001];
	scanf("%s", s);
	for(int i = 0; s[i] != '\0';i++){
		if(s[i]+n > 'Z'){
			printf("%c", s[i]+n-26);
		}else{
			printf("%c", s[i]+n);
		}
	}
	puts("");
	return 0;
}