#include <stdio.h>
#include <string.h>
int main(){
	char b[101];
	int a, c;
	scanf ("%d", &a);
	getchar();
	scanf("%[^\n]", &b);
	c= strlen(b);
	if (c>a){
		for (int i=0; i<a; i++){
			printf("%c", b[i]);
		}
		printf("...\n");
	}
	else{
		for(int i=0; i<c; i++){
			printf("%c", b[i]);
		}
	}
	
	return 0;
}