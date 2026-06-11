#include <stdio.h>

	int main(){
		int n;
		char c[10002];
		scanf("%d %s",&n, c);
		
		for(int i=0; c[i] != '\0'; i++){
			c[i] = 'A' + (c[i]-'A'+n) % 26;
		}
		printf("%s\n",c);
		return 0;
	}