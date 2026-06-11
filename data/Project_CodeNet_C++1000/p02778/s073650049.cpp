#include <stdio.h>

char str[101];

int main(void){
scanf("%s", str);
for (int i = 0; str[i]; i++) {
	str[i] = 'x';
}
puts(str);
return 0;
}
