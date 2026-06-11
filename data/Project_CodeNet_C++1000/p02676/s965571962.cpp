#include <stdio.h>
#include <string.h>
int main (){
	int g;
	char c[101];
	scanf("%d ", &g);
	scanf("%s", c);
	int len = strlen(c);
	if (len <= g) {
		printf("%s\n",c);
	}
	else{
		for (int i = 0; i < g; i++){
			printf("%c", c[i]);
		}
		printf("...\n");
	}
	return 0;
}