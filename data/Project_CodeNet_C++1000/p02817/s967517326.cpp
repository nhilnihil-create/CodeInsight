#include <stdio.h>
int main(){
	char first[101];
	char second[101];
	scanf("%s", &first);
	scanf("%s", &second);
	printf("%s%s", &second, &first);
	getchar();
	
	return 0;
}
