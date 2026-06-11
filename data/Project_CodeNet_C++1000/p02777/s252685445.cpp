#include <stdio.h>
#include <string.h>
int main(){
	char name1[15], name2[15], name3[15];
	int num1, num2;
	scanf("%s %s\n%d %d\n%s", &name1, &name2, &num1, &num2, &name3);

	if (strcmp(name1, name3) == 0){
		printf("%d %d", num1 - 1, num2);
	} else if (strcmp(name2, name3) == 0){
		printf("%d %d", num1, num2 -1);
	}
	return 0;
}