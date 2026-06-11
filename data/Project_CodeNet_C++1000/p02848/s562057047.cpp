#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	getchar();
	char x[100000];
	scanf("%[^\n]", &x);
	for (int i=0; x[i]!='\0'; i++){
		int result = x[i]+t;
		if (result > 'Z'){
			result-=26;
		}
		printf("%c", result);
	}
	return 0;
}
