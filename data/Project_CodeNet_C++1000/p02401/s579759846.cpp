#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Delete_space(char *str){
	char *p = str;

	while (*str != '\0'){
		if (!isspace(*str)){
			*p = *str;
			p++;
		}
		str++;
	}
	*p = '\0';
}

int main(){
	int i=0, j=0,k=0;
	char a[128], a2[128];
	char op;
	int x, y, z[128] = { 0 };


	for (k= 0;; k++){
		i = 0;
		op = 0;
		x = 0;
		y = 0;
		for (j = 0; j < 128; j++){
			a[j] = 0;
			a2[j] = 0;
			
		}
		gets(a);

		Delete_space(a);

		for (j = 0; a[i] >= '0'&&a[i]<='9'; i++){
			a2[j] = a[i]; j++;
		}
		a2[j] = '\0'; x = atoi(a2);

		op = a[i]; i++;
		if (strstr(a,"?")!=NULL){
			break;
		}
		for (j = 0; a[i] >= '0'&&a[i] <= '9'; i++){
			a2[j] = a[i]; j++;
		}
		a2[j] = '\0'; y = atoi(a2);


		switch (op){
		case '+': z[k] = x + y; break;
		case '-': z[k] = x - y; break;
		case '*': z[k] = x * y; break;
		case '/': z[k] = x / y; break;
		case '%': z[k] = x % y; break;
		}

	}
	for (j = 0; j <k; j++){
		printf("%d\n", z[j]);
	}


	return 0;
}