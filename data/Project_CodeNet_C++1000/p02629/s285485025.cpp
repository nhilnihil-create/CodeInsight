#include <stdio.h>
#include <string.h>
int main()
{
long long int a;
int  i = 0, remain;
scanf("%lld", &a);
char str[100];
while(a != 0){
	remain = a % 26;
	
	if(remain == 0){
		str[i++] = 'z';
		a = a/26 - 1;
	}else{
		str[i++] = remain + 96;
		a = a/26;
	}	
}
str[i] = '\0';
for(int j = strlen(str) - 1;j >= 0; j--){
	printf("%c",str[j]);
}


return 0;
}