#include <stdio.h>
#include <string.h>

int main(){
char str[25];
scanf("%s", str);
for(int i = 0; i < 3;i++){
	printf("%c", str[i]);
}
return 0;
}