#include <stdio.h>
int main(){
	char coffee[21];
	scanf("%s", coffee);
	if(coffee[2] == coffee[3] && coffee[4] == coffee[5]){printf("Yes");}
	else{printf("No");}
	return 0;
}