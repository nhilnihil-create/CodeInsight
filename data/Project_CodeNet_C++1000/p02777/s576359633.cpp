#include<stdio.h>
#include<string.h>
int main(){
	int a, b;
	char s[11];
	char t[11];
	char u[11];
	
	scanf("%s %s\n", &s, &t);
	scanf("%d %d\n", &a, &b);
	scanf("%s", &u);

	if(strcmp(s,u) == 0){
		printf("%d %d\n", a-1, b);
	}
	else if(strcmp(t, u) == 0){
		printf("%d %d\n", a, b-1);
	}
	return 0;
}