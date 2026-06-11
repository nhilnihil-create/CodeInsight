#include<stdio.h>
#include<string.h>

int main(){
	
	char str1[15], str2[15], trash[15];
	int balls1, balls2;
	
	scanf("%s %s", &str1, &str2);
	scanf("%d %d", &balls1, &balls2);
	scanf("%s", &trash);
	
	(strcmp(trash, str1) == 0) ? balls1-- : balls2--;
	printf("%d %d\n", balls1, balls2);
	
	return 0;
}