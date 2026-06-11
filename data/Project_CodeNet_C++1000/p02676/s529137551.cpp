#include <stdio.h>
#include <string.h>

int main (){
	int k;
	char str[160];
	
	scanf("%d", &k);
	scanf("%s", str);
	getchar();
	
	int len = strlen(str);
	if (len <= k){
		printf("%s\n", str);
	}
	else{
		for (int i = 0; i < k; i++){
			printf("%c", str[i]);
		}
		puts("...");
	}
	return 0;
}