#include <stdio.h>
#include <string.h>

int main(){
	
	char S [30]; char T [30]; char N [30];
		int a, b;
			scanf("%s %s", &S, &T);
			scanf("%d %d", &a, &b);
			scanf("%s", &N);
	
	if (strcmp(S, N)==0) {
			printf("%d %d", a-1,b);
	}
	else if (strcmp(T,N)==0) {
			printf("%d %d", a,b-1);
	}

	return 0;
}