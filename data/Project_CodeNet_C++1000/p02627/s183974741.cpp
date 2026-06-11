#include<stdio.h>
#include<string.h>
int main(){
	int a;
	scanf("%s", &a);
	char str(255);
	if(a>='A' && a<='Z'){
		printf("A\n");
	}
	else if (a>='a' && a<='z'){
		printf("a\n");
	}
	return 0;
}